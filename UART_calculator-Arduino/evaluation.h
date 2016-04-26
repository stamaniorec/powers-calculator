/* Written by Stanimir Bogdanov */

#ifndef EVALUATION_H
#define EVALUATION_H

#include "string_t.h"
#include "utils.h"

bool_t has_precedence(char op1, char op2);
double apply_op(char op, double b, double a);
long double evaluate(string_t* expr);

#endif
