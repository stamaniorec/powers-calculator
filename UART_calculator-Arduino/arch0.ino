#include <LiquidCrystal.h>
#include <ctype.h>

extern "C"{
  #include "evaluation.h"
  #include "exponentiated_number.h"
  #include "newton_method.h"
  #include "stack.h"
  #include "string.h"
  #include "validation_and_formatting.h"
}

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(23,25, 22,24,26,28);

String values[2][10] = {{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"},
                       { "+", "-", "*", "/", "^", "(", ")", ".", "DEL", "ENTER"}};
int num_buttons = 10;
int buttons[] = {12,11,10,9,8,7,6,5,4,3,2};

short fn_val = 0;
boolean fn_pin = 13;

String expr = "";

void printt(String string) {
    int length = string.length();
    String first_half;
    String second_half;
    if(length < 8) {
       first_half = string.substring(0,length);
       second_half = "";
    } else {
       first_half = string.substring(0,8);
       if(length < 16)
         second_half = string.substring(8,length);
       else
        second_half = string.substring(8,16); 
    }
    
    lcd.print(first_half);
    lcd.setCursor(0,1);
    lcd.print(second_half);
    //lcd.setCursor(0,0); // TO BE TESTED
}

boolean debounce(int pin, boolean last) {
  boolean current = digitalRead(pin);
  if (last != current) {
    delay(5);
    current = digitalRead(pin);
  }
  return current;
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  lcd.begin(16,2);
  //lcd.begin(8,2);
  lcd.clear();
  for(int i = 0; i < num_buttons; ++i)
    pinMode(buttons[i], INPUT);
   pinMode(fn_pin, INPUT);
}

void transmit1(String transmission){
  Serial1.write("S");
  for(int i=0; i < transmission.length(); i++)
    Serial1.write(("s" + String(transmission[i])).c_str());
  Serial1.write("E");
}

String receive1(){
  String result = "";
  boolean stop = false;
  boolean char_received = false;
  char curr_char = 's';
  
  while (!(Serial1.available() > 0 && Serial1.read() == 'S'));
  while (!stop){
    if(Serial1.available()>0){
      curr_char = Serial1.read();
    }
    switch(curr_char){
      case 'S':
        break;
      case 'E':
        stop = true;
        break;
      case 's':
        char_received = false;
        break;
      default:
        if(!char_received)
          result += curr_char;
        char_received = true;
        break;
    }
  }
  return result;
}

String handle_expression(String expression){
  int power = expr.indexOf('^');
  if(power == -1){
     return normal_eval(expression);
  }else{      
    while(digitalRead(buttons[9]) == HIGH);
    String base_str = expr.substring(0, power);
    String exponent_str = expr.substring(power+1);
    
    string_t bas_str, exp_str;
    
    char bas_buf[50], exp_buf[50], res_buf[50];
    
    base_str.toCharArray(bas_buf, 50);
    exponent_str.toCharArray(exp_buf, 50);
    
    init_string(&bas_str, bas_buf);
    init_string(&exp_str, exp_buf);
    
    long double result = newton_loop(evaluate(&bas_str), evaluate(&exp_str));
    
    dtostrf(result, 3, 4, res_buf);
    String out(res_buf);
    return out;
  }
}

long double newton_loop(long double b, long double e){
  exponentiated_number exp_num;
  newton_method_instance newton;
  long double x0, next_;
  
  /*Serial.println("!!!");
  char buf1[50], buf2[50];
  dtostrf(b, 3, 4, buf1);
  dtostrf(e, 3, 4, buf2);
  String b_str(buf1);
  String e_str(buf2);
  
  Serial.println(b_str);
  Serial.println(e_str);*/
  
  init_exponentiated_number(&exp_num, b, e);
  x0 = pick_x0(exp_num) X0_FORCED_ERROR;
  init_newton_method_instance(&newton, x0, NEWTON_METHOD_TOLERANCE, NEWTON_METHOD_MAX_ITR, &exp_num);
  
  Serial.println(int(exp_num.power_numerator));
  Serial.println(int(exp_num.power_denominator));
  
  while (true){
    //while(digitalRead(buttons[8]) == HIGH);
    //while(digitalRead(buttons[9]) == HIGH);
    if(digitalRead(buttons[8]) == HIGH){
      next_ = next(&exp_num, &newton);
      Serial.println("IMportant info to follow");
      
      
      if(next_ == -5432.1) {
        char buf1[50], buf2[50];
  dtostrf(newton.cur_itr, 3, 4, buf1);
  dtostrf(newton.x1, 3, 4, buf2);
  String b_str(buf1);
  String e_str(buf2);
        Serial.println("After " + b_str + " iterations, root = " + e_str + "\n");
    } else if(next_ == -8080.0 || next_ == -1234.5) {
        Serial.println("out of order! go fuck a goat and come back later\n"); 
    } else {
              char buf1[50], buf2[50];
  dtostrf(newton.cur_itr, 3, 4, buf1);
  dtostrf(next_, 3, 4, buf2);
  String b_str(buf1);
  String e_str(buf2);
        Serial.println("   At Iteration no. " + b_str + ", x = " + e_str + "\n");
        //return 1;
    }
      
      
      char buf[50];
      Serial.println(int(next_));
      dtostrf(next_, 3, 4, buf);
      String out(buf);
      Serial.println(buf);
      while(digitalRead(buttons[8]) == HIGH);
    }
    if(digitalRead(buttons[9]) == HIGH){
      Serial.println("imma out of hereh");
      long double fastf = fastforward(&exp_num, &newton);
      char buf1[50];
  dtostrf(fastf, 3, 4, buf1);
  String b_str(buf1);
  Serial.println(b_str);
      return fastf;
    }
  }
}

String normal_eval(String expression){
  string_t res_str;
  char buf[50];
  expression.toCharArray(buf, 50);
  init_string(&res_str, buf);
  long double result = evaluate(&res_str);
  dtostrf(result, 3, 4, buf);
  String out(buf);
  return out;
}


void handle_buttons() {
  // is fn enabled
  fn_val = (digitalRead(fn_pin) == HIGH) ? 1 : 0;

  for(int i = 0; i < num_buttons; ++i) {
    int state = digitalRead(buttons[i]);
    if(state == HIGH) {
      lcd.clear();
      if(values[fn_val][i] != "ENTER") {
        if(values[fn_val][i] == "DEL") {
          expr = String(expr.substring(0,expr.length()-1));
        } else {
          expr += values[fn_val][i];
        }
        transmit1(expr);
        Serial.println(expr);
      } else {
        String result = handle_expression(expr);
        Serial.println("=");
        Serial.println(result);
        transmit1(result);
        result = receive1();
        printt(result);
      }
      while(digitalRead(buttons[i]) == HIGH);
    }
  }
}

void loop() {
  lcd.display();
  //printt("hello world");
  handle_buttons();
  delay(100);
}
