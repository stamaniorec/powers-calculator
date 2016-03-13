// Written by Stanimir Bogdanov
// don't forget to compile with -lm option
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

// Generic Linked List implementation below thanks to pseudomuto
typedef void (*freeFunction)(void *);
typedef enum { FALSE, TRUE } bool;
typedef bool (*listIterator)(void *);

typedef struct _listNode {
    void *data;
    struct _listNode *next;
} listNode;

typedef struct {
    int logicalLength;
    int elementSize;
    listNode *head;
    listNode *tail;
    freeFunction freeFn;
} list;

void list_new(list *list, int elementSize, freeFunction freeFn)
{
    assert(elementSize > 0);
    list->logicalLength = 0;
    list->elementSize = elementSize;
    list->head = list->tail = NULL;
    list->freeFn = freeFn;
}

void list_destroy(list *list)
{
    listNode *current;
    while(list->head != NULL) {
        current = list->head;
        list->head = current->next;

        if(list->freeFn) {
            list->freeFn(current->data);
        }

        free(current->data);
        free(current);
    }
}

void list_prepend(list *list, void *element)
{
    listNode *node = malloc(sizeof(listNode));
    node->data = malloc(list->elementSize);
    memcpy(node->data, element, list->elementSize);

    node->next = list->head;
    list->head = node;

    // first node?
    if(!list->tail) {
        list->tail = list->head;
    }

    list->logicalLength++;
}

void list_append(list *list, void *element)
{
    listNode *node = malloc(sizeof(listNode));
    node->data = malloc(list->elementSize);
    node->next = NULL;

    memcpy(node->data, element, list->elementSize);

    if(list->logicalLength == 0) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->logicalLength++;
}

void list_for_each(list *list, listIterator iterator)
{
    assert(iterator != NULL);

    listNode *node = list->head;
    bool result = TRUE;
    while(node != NULL && result) {
        result = iterator(node->data);
        node = node->next;
    }
}

void list_head(list *list, void *element, bool removeFromList)
{
    assert(list->head != NULL);

    listNode *node = list->head;
    memcpy(element, node->data, list->elementSize);

    if(removeFromList) {
      list->head = node->next;
      list->logicalLength--;
    
      free(node->data);
      free(node);
    }
}

void list_tail(list *list, void *element)
{
    assert(list->tail != NULL);
    listNode *node = list->tail;
    memcpy(element, node->data, list->elementSize);
}

int list_size(list *list)
{
    return list->logicalLength;
}

// Generic Stack implementation below thanks to pseudomuto
typedef struct {
    list *list;
} stack;

int stack_size(stack *s)
{
    return list_size(s->list);
}

void stack_new(stack *s, int elementSize, freeFunction freeFn)
{
    s->list = malloc(sizeof(list));
    // make sure the malloc call didn't fail...
    assert(s->list != NULL);

    list_new(s->list, elementSize, freeFn);
}

void stack_destroy(stack *s)
{
    list_destroy(s->list);
    free(s->list);
}

void stack_push(stack *s, void *element)
{
    list_prepend(s->list, element);
}

void stack_pop(stack *s, void *element)
{
    // don't pop an empty stack!
    assert(stack_size(s) > 0);

    list_head(s->list, element, TRUE);
}

void stack_peek(stack *s, void *element)
{
    assert(stack_size(s) > 0);
    list_head(s->list, element, FALSE);
}

bool stack_empty(stack* s) {
    return stack_size(s) == 0;
}

// String implementation, this time by me
typedef struct {
    int length;
    int capacity;
    char* string;
} string_t;

void init_string(string_t* string, char* initial_value) {
    int length = strlen(initial_value);
    string->length = length;
    string->capacity = length * 2;
    string->string = malloc(sizeof(char) * length);

    int i;
    for(i = 0; i < length; ++i) {
        string->string[i] = initial_value[i];
    }
    string->string[length] = '\0';
}

void resize_if_needed(string_t* string, char* value) {
    int length = strlen(value);
    int new_length = string->length + length;
    if(string->capacity < new_length) {
        int new_capacity = new_length * 2;
        char* new_buffer = malloc(sizeof(char) * new_capacity);
        strcpy(new_buffer, string->string);
        free(string->string);
        string->string = new_buffer;
        string->capacity = new_capacity;
    }
}

void append(string_t* string, char* value) {
    resize_if_needed(string, value);
    int new_length = string->length + strlen(value);
    string->length = new_length;
    strcat(string->string, value);
}

void prepend(string_t* string, char* value) {
    resize_if_needed(string, value);
    int length = strlen(value);
    int i;
    for(i = string->length-1; i >= 0; --i) {
        string->string[i+length] = string->string[i];
    }
    for(i = 0; i < length; ++i) {
        string->string[i] = value[i];
    }
}

void destroy_string(string_t* string)
{
    free(string->string);
}

// --- --- --- --- --- Actual program below

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

// Formats the given infix expression string by adding whitespace around operators
// Returns a newly built string
string_t* format_expression_string(string_t* expr) {
    string_t* result = malloc(sizeof(string_t));
    init_string(result, "");

    int length = strlen(expr->string);
    for(int i = 0; i < length-1; ++i) {
        char cur_char = expr->string[i];
        char next_char = expr->string[i+1];

        // Convert char to string
        char str[2] = "\0"; // gives {\0, \0}
        str[0] = cur_char;
        append(result, str);

        if(isdigit(cur_char) && is_operator(next_char)) {
            append(result, " ");
        }

        if(is_operator(cur_char) && isdigit(next_char)) {
            append(result, " ");
        }

        if(is_operator(cur_char) && is_operator(next_char)) {
            append(result, " ");
        }
    }

    append(result, &expr->string[length-1]);
    return result;
}

// Returns whether op1 has a higher precedence than op2
bool has_precedence(char op1, char op2) {
    if (op2 == '(' || op2 == ')')
        return FALSE;

    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return FALSE;
    else
        return TRUE;   
}

// Applies the given operation to the given arguments
double apply_op(char op, double b, double a) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            ;// division_by_zero = true;
        else
            return a / b;
    }
    return 0;
}

// The algorithm uses two stacks - one for numbers and one for operators
// They hold the postfix representation of the expression
// When evaluating, the two top items in the stack for numbers are popped
// as well as the top one from the operator stack, and the operation is applied.

long double evaluate(string_t* expr) {
    string_t* formatted = format_expression_string(expr);

    stack values;
    stack_new(&values, sizeof(double), NULL);

    stack ops;
    stack_new(&ops, sizeof(char), NULL);

    int length = strlen(formatted->string);

    for(int i = 0; i < length; i++) {
        // Current token is a whitespace, skip it
        if (formatted->string[i] == ' ')
            continue;

        // Current token is a number, push it to stack for numbers
        if((formatted->string[i] >= '0' && formatted->string[i] <= '9') || (formatted->string[i] == '.')) {
            string_t buf;
            init_string(&buf, "");

            // There may be more than one digits in number
            while(i < length &&
                ((formatted->string[i] >= '0' && formatted->string[i] <= '9')) || formatted->string[i] == '.') {
                char as_string[2] = "\0";
                as_string[0] = formatted->string[i++];
                append(&buf, as_string);
            }

            double result = atof(buf.string);
            stack_push(&values, &result);
        } else if(formatted->string[i] == '(') {
            // Current token is an opening brace, push it to 'ops'
            char as_string[2] = "\0";
            as_string[0] = formatted->string[i];
            stack_push(&ops, as_string);
        } else if(formatted->string[i] == ')') {
            // Closing brace encountered, solve entire brace
            while(TRUE) {
                char top;
                stack_peek(&ops, &top);
                if(top == '(') break;

                double a, b;
                stack_pop(&values, &a);
                stack_pop(&values, &b);

                char op;
                stack_pop(&ops, &op);

                double result = apply_op(op, a, b);
                stack_push(&values, &result);
            }

            char unused;
            stack_pop(&ops, &unused); // pop (
        } else if(is_operator(formatted->string[i])) {
            // While top of 'ops' has same or greater precedence to current
            // token, which is an operator. Apply operator on top of 'ops'
            // to top two elements in values stack
            while(TRUE) {
                char top = '(';
                if(!stack_empty(&ops))
                    stack_peek(&ops, &top);
                if(stack_empty(&ops) || !has_precedence(formatted->string[i], top)) break;

                double a, b;
                stack_pop(&values, &a);
                stack_pop(&values, &b);
                char op;
                stack_pop(&ops, &op);

                double result = apply_op(op, a, b);
                
                // !!!!!!!!!!!!!!!!!!!!
                // if(division_by_zero) {
                //  return -255;
                // }

                stack_push(&values, &result);
            }
        
            // Push current token to 'ops'.
            char as_string[2] = "\0";
            as_string[0] = formatted->string[i];
            stack_push(&ops, as_string);
        }
    }
    
    // Entire expression has been parsed at this point, apply remaining
    // ops to remaining values
    while(!stack_empty(&ops)) {
        double a, b;
        stack_pop(&values, &a);
        stack_pop(&values, &b);

        char op;
        stack_pop(&ops, &op);
        double result = apply_op(op, a, b);
        stack_push(&values, &result);
    }

    // Top of 'values' contains result, return it
    double result;
    stack_pop(&values, &result);
    return result;
}

// Returns whether the given infix expression string has balanced paranthesis
bool are_parenthesis_balanced(string_t* expr)
{
    int i = 0;

    stack s;
    stack_new(&s, sizeof(char), NULL);

    int expr_len = strlen(expr->string);

    while(i < expr_len) {
        if(expr->string[i] == '(')
            stack_push(&s, &expr->string[i]);

        if(expr->string[i] == ')')
        {
            // A pair isn't formed, therefore they're not balanced
            if(stack_empty(&s))
                return FALSE;

            // e.g. {(})
            char popped;
            stack_pop(&s, &popped);
            if(popped != '(')
                return FALSE;
        }
        i++;
    }

    return stack_empty(&s);
}

// Returns whether the given string is a valid infix expression
// It is very naive and by no means works in all cases
bool valid_expression(string_t* expr) {
    int length = strlen(expr->string);
    if(length == 0) return TRUE;

    char first_char = expr->string[0];
    if(first_char == '*' || first_char == '/')
        return FALSE;
       
    char last_char = expr->string[length-1];
    if(last_char == '+' || last_char == '-' || last_char == '*' || last_char == '/')
        return FALSE;
       
    for(int i = 0; i < length-1; ++i) {
        char cur = expr->string[i];
        char next = expr->string[i+1];
        if((is_operator(cur) && cur != '(' && cur != ')') && (is_operator(next) && next != '(' && next != ')'))
            return FALSE;
    }
       
    for(int i = 0; i < length-1; ++i) {
        char cur = expr->string[i];
        char next = expr->string[i+1];
        if(cur == '(' && next == ')')
            return FALSE;
        if(cur == '(' && !isdigit(next) && next != '(')
            return FALSE;
        if(cur == ')' && next != '+' && next != '-' && next != '*' && next != '/' && next != ')')
            return FALSE;
    }
       
    for(int i = 0; i < length-1; ++i) {
    char cur = expr->string[i];
    char next = expr->string[i+1];
    if((cur == '+' || cur == '-' || cur == '*' || cur == '/') && (!isdigit(next) && next != '('))
        return FALSE;
    }

    if(!are_parenthesis_balanced(expr))
        return FALSE;
       
    return TRUE;
}

// Prepends a 0 if there's a - or + sign in the beginning of the expression
void improve_expression(string_t* expr) {
    if(strlen(expr->string) == 0) return;

    if(expr->string[0] == '+' || expr->string[0] == '-')
        prepend(expr, "0");
}

long long gcd(long long a, long long b)
{
    if(a == 0)
        return b;
    else if(b == 0)
        return a;

    if(a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

typedef struct 
{
    long double base;
    long long power_numerator;
    long long power_denominator;
} exponentiated_number;

#define POWER_CONVERSION_PRECISION 1000

void init_exponentiated_number(exponentiated_number* exp_num, long double base, long double exponent)//char* expression)
{
    // char* base = strtok(expression, "^");
    // char* exponent = strtok(NULL, "^");

    // Convert exponent to fraction and simplify, e.g. 5.2 = 52/10=26/5
    // long double frac = atof(exponent);
    long long gcd_ = gcd(round(exponent * POWER_CONVERSION_PRECISION), POWER_CONVERSION_PRECISION);
    exp_num->base = base;
    exp_num->power_numerator = round(exponent * POWER_CONVERSION_PRECISION) / gcd_;
    exp_num->power_denominator = POWER_CONVERSION_PRECISION / gcd_;
}

typedef struct
{
    long double x0;
    long double x1;
    long double tolerance;
    int max_iterations;
    int cur_itr;
    exponentiated_number* exp_num;
} newton_method_instance;

void init_newton_method_instance(newton_method_instance* newton, long double x0,
    long double tolerance, long double max_iterations, exponentiated_number* exp_num)
{
    newton->x0 = x0;
    newton->x1 = 0.0;
    newton->tolerance = tolerance;
    newton->max_iterations = max_iterations;
    newton->cur_itr = 0;
    newton->exp_num = exp_num;
}

// The x0 returned is actually the solution to the equation
long double pick_x0(exponentiated_number exp_num)
{
    return pow(exp_num.base, (long double)exp_num.power_numerator/exp_num.power_denominator);
}

// The function on which Newton's method is applied
long double f(long double x, exponentiated_number exp_num)
{
    return pow(x, exp_num.power_denominator) - pow(exp_num.base, exp_num.power_numerator);
}

#define DERIVATIVE_DELTA 1.0e-6

// Returns the derivative of the function on which Newton's method is applied
long double df(long double x, exponentiated_number exp_num)
{
    const double delta = DERIVATIVE_DELTA;
    long double x1 = x - delta;
    long double x2 = x + delta;
    long double y1 = f(x1, exp_num);
    long double y2 = f(x2, exp_num);
    return (y2 - y1) / (x2 - x1);
}

long double newton_iteration_statuses[] = {-5432.1, -8080.0, -1234.5};
enum newton_iteration_statuses_enum { SOLUTION_FOUND, NaN, INF };

// Returns the value of the next iteration of Newton's method or the appropriate error code
long double next(exponentiated_number* exp_num, newton_method_instance* newton)
{
    long double y = f(newton->x0, *exp_num);
    long double yd = df(newton->x0, *exp_num);
    long double h = y / yd;
    newton->x1 = newton->x0 - h;

    ++newton->cur_itr;

    if(isnan(newton->x1)) {
        return newton_iteration_statuses[NaN];
    }

    if(isinf(newton->x1)) {
        return newton_iteration_statuses[INF];
    }

    if(fabs(h) < newton->tolerance) {
        return newton_iteration_statuses[SOLUTION_FOUND];
    }

    newton->x0 = newton->x1;
    return newton->x1;
}

// Continuously runs Newton's method iterations until a solution is found
long double fastforward(exponentiated_number* exp_num, newton_method_instance* newton) {
    for(int i = newton->cur_itr; i < newton->max_iterations; ++i) {
        long double next_ = next(exp_num, newton);
        if(next_ == newton_iteration_statuses[SOLUTION_FOUND]) return newton->x1;
    }
    return newton_iteration_statuses[NaN];
}

int print_next_newton_iteration(long double next_value, newton_method_instance newton)
{
    if(next_value == newton_iteration_statuses[SOLUTION_FOUND]) {
        printf("After %3d iterations, root = %8.6Lf\n", newton.cur_itr, newton.x1);
    } else if(next_value == newton_iteration_statuses[INF] || next_value == newton_iteration_statuses[NaN]) {
        printf("sorry my nigga\n"); 
    } else {
        printf("   At Iteration no. %3d, x = %9.6Lf\n", newton.cur_itr, next_value);
        return 1;
    }

    return 0;
}

#define NEWTON_METHOD_TOLERANCE 0.00001
#define NEWTON_METHOD_MAX_ITR 10000
#define X0_FORCED_ERROR - 10

void demo_steps() {
    printf("Demonstrating step-by-step calculation and a fast-forward.\n");
    char expression[255] = "(10+7.66*2)^(14.4/2)";

    char* base = strtok(expression, "^");
    char* exponent = strtok(NULL, "^");

    string_t base_eval, exponent_eval;
    init_string(&base_eval, base);
    init_string(&exponent_eval, exponent);
    long double b = evaluate(&base_eval);
    long double e = evaluate(&exponent_eval);

    printf("The actual expression is: %Lf ^ %Lf\n", b, e);

    char final[255];

    exponentiated_number exp_num;
    init_exponentiated_number(&exp_num, b, e);

    long double x0 = pick_x0(exp_num) X0_FORCED_ERROR;

    newton_method_instance newton;
    init_newton_method_instance(&newton, x0, NEWTON_METHOD_TOLERANCE, NEWTON_METHOD_MAX_ITR, &exp_num);

    long double next_ = next(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);

    next_ = next(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);

    next_ = next(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);

    next_ = fastforward(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);   
}

void demo_evaluate_expression() {
    printf("Here comes a very nasty expression.\n");
    string_t expression;
    init_string(&expression, "(429*(9394-(934+43/21))/3.14)-341.3*45.2-3.14");
    improve_expression(&expression);
    string_t* formatted = format_expression_string(&expression);
    printf("%Lf\n", evaluate(&expression));
    destroy_string(&expression);
    destroy_string(formatted);
}

int main(int argc, char const *argv[])
{
    demo_steps();
    demo_evaluate_expression();

    return 0;
}
