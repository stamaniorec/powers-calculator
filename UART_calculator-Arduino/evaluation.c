#include <string.h>
#include <stdlib.h>

#include "evaluation.h"
#include "stack.h"
#include "validation_and_formatting.h"

/* Returns whether op1 has a higher precedence than op2 */
bool_t has_precedence(char op1, char op2) {
    if (op2 == '(' || op2 == ')')
        return FALSE;

    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return FALSE;
    else
        return TRUE;   
}

/* Applies the given operation to the given arguments */
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
            ;/* division_by_zero = true; */
        else
            return a / b;
    }
    return 0;
}

/*
The algorithm uses two stacks - one for numbers and one for operators
They hold the postfix representation of the expression
When evaluating, the two top items in the stack for numbers are popped
as well as the top one from the operator stack, and the operation is applied.
*/

long double evaluate(string_t* expr) {
    int i, length;
    double result, a, b;
    char as_string[2] = "\0";
    char top, op, unused;
    stack values, ops;

    string_t formatted;
    init_string(&formatted, "");
    format_expression_string(expr, &formatted);

    stack_new(&values, sizeof(double));
    stack_new(&ops, sizeof(char));

    length = strlen(formatted.string);

    for(i = 0; i < length; i++) {
        /* Current token is a whitespace, skip it */
        if (formatted.string[i] == ' ')
            continue;

        /* Current token is a number, push it to stack for numbers */
        if((formatted.string[i] >= '0' && formatted.string[i] <= '9') || (formatted.string[i] == '.')) {
            string_t buf;
            init_string(&buf, "");

            /* There may be more than one digits in number */
            while((i < length) &&
                (((formatted.string[i] >= '0') && (formatted.string[i] <= '9')) || (formatted.string[i] == '.'))) {
                as_string[0] = formatted.string[i++];
                append(&buf, as_string);
            }

            result = atof(buf.string);
            stack_push(&values, &result);
        } else if(formatted.string[i] == '(') {
            /* Current token is an opening brace, push it to 'ops' */
            as_string[0] = formatted.string[i];
            stack_push(&ops, as_string);
        } else if(formatted.string[i] == ')') {
            /* Closing brace encountered, solve entire brace */
            while(TRUE) {
                stack_peek(&ops, &top);
                if(top == '(') break;

                stack_pop(&values, &a);
                stack_pop(&values, &b);

                stack_pop(&ops, &op);

                result = apply_op(op, a, b);
                stack_push(&values, &result);
            }

            stack_pop(&ops, &unused); /* pop ( */
        } else if(is_operator(formatted.string[i])) {
            /* While top of 'ops' has same or greater precedence to current
               token, which is an operator. Apply operator on top of 'ops'
               to top two elements in values stack */
            while(TRUE) {
                top = '(';
                if(!stack_empty(&ops))
                    stack_peek(&ops, &top);
                if(stack_empty(&ops) || !has_precedence(formatted.string[i], top)) break;

                stack_pop(&values, &a);
                stack_pop(&values, &b);
                stack_pop(&ops, &op);

                result = apply_op(op, a, b);
                
                /* !!!!!!!!!!!!!!!!!!!!
                    if(division_by_zero) {
                        return -255;
                    } */

                stack_push(&values, &result);
            }
        
            /* Push current token to 'ops'. */
            as_string[0] = formatted.string[i];
            stack_push(&ops, as_string);
        }
    }
    
    /* Entire expression has been parsed at this point, apply remaining
       ops to remaining values */
    while(!stack_empty(&ops)) {
        stack_pop(&values, &a);
        stack_pop(&values, &b);

        stack_pop(&ops, &op);
        result = apply_op(op, a, b);
        stack_push(&values, &result);
    }

    /* Top of 'values' contains result, return it */
    stack_pop(&values, &result);
    return result;
}
