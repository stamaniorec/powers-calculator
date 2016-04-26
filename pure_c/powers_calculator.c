/* Written by Stanimir Bogdanov */
/* don't forget to compile with -lm option */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "string_t.h"
#include "exponentiated_number.h"

#include "validation_and_formatting.h"
#include "evaluation.h"
#include "newton_method.h"

void demo_steps() {
    long double x0, next_, b, e;
    char* base;
    char* exponent;
    string_t base_eval, exponent_eval;
    newton_method_instance newton;
    exponentiated_number exp_num;
    char expression[255] = "(10+7.66*2)^(14.4/2)";
    printf("Demonstrating step-by-step calculation and a fast-forward.\n");

    base = strtok(expression, "^");
    exponent = strtok(NULL, "^");

    init_string(&base_eval, base);
    init_string(&exponent_eval, exponent);
    b = evaluate(&base_eval);
    e = evaluate(&exponent_eval);

    printf("The actual expression is: %Lf ^ %Lf\n", b, e);

    init_exponentiated_number(&exp_num, b, e);

    x0 = pick_x0(exp_num) X0_FORCED_ERROR;

    init_newton_method_instance(&newton, x0, NEWTON_METHOD_TOLERANCE, NEWTON_METHOD_MAX_ITR, &exp_num);

    next_ = next(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);

    next_ = next(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);

    next_ = next(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);

    next_ = fastforward(&exp_num, &newton);
    print_next_newton_iteration(next_, newton);   
}

void demo_evaluate_expression() {
    string_t expression, formatted;
    printf("Here comes a very nasty expression.\n");    
    init_string(&expression, "(429*(9394-(934+43/21))/3.14)-341.3*45.2-3.14");
    improve_expression(&expression);
    init_string(&formatted, "");
    format_expression_string(&expression, &formatted);
    printf("%Lf\n", evaluate(&expression));
}

int main()
{
    demo_steps();
    demo_evaluate_expression();

    return 0;
}
