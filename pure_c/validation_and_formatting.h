/* Written by Stanimir Bogdanov */

#ifndef VALIDATION_AND_FORMATTING_H
#define VALIDATION_AND_FORMATTING_H

#include "string_t.h"

bool are_parenthesis_balanced(string_t* expr);
bool valid_expression(string_t* expr);
void improve_expression(string_t* expr);
void format_expression_string(string_t* expr, string_t* result);

#endif