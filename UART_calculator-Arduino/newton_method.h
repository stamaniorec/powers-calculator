/* Written by Stanimir Bogdanov */

#ifndef NEWTON_METHOD_H
#define NEWTON_METHOD_H

#include "exponentiated_number.h"

typedef struct
{
    long double x0;
    long double x1;
    long double tolerance;
    int max_iterations;
    int cur_itr;
    exponentiated_number* exp_num;
} newton_method_instance;

#define NEWTON_METHOD_TOLERANCE 0.00001
#define NEWTON_METHOD_MAX_ITR 10000
#define X0_FORCED_ERROR - 10

void init_newton_method_instance(newton_method_instance* newton, long double x0,
    long double tolerance, long double max_iterations, exponentiated_number* exp_num);

long double pick_x0(exponentiated_number exp_num);

#define DERIVATIVE_DELTA 1.0e-6
long double df(long double x, exponentiated_number exp_num);
long double f(long double x, exponentiated_number exp_num);

enum newton_iteration_statuses_enum { SOLUTION_FOUND, NaN, INF };

long double next(exponentiated_number* exp_num, newton_method_instance* newton);

long double fastforward(exponentiated_number* exp_num, newton_method_instance* newton);
int print_next_newton_iteration(long double next_value, newton_method_instance newton);

#endif