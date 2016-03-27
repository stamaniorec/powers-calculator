#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// #include "validation_and_formatting.h"
#include "string_t.h"
#include "utils.h"
#include "stack.h"

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