#include <stdio.h>
#include <math.h>
#include "newton_method.h"
#include "utils.h"

long double newton_iteration_statuses[] = {-5432.1, -8080.0, -1234.5};

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

/* The x0 returned is actually the solution to the equation */
long double pick_x0(exponentiated_number exp_num)
{
    return pow(exp_num.base, (long double)exp_num.power_numerator/exp_num.power_denominator);
}

/* The function on which Newton's method is applied */
long double f(long double x, exponentiated_number exp_num)
{
    return pow(x, exp_num.power_denominator) - pow(exp_num.base, exp_num.power_numerator);
}

/* Returns the derivative of the function on which Newton's method is applied */
long double df(long double x, exponentiated_number exp_num)
{
    const double delta = DERIVATIVE_DELTA;
    long double x1 = x - delta;
    long double x2 = x + delta;
    long double y1 = f(x1, exp_num);
    long double y2 = f(x2, exp_num);
    return (y2 - y1) / (x2 - x1);
}

/* Returns the value of the next iteration of Newton's method or the appropriate error code */
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

/* Continuously runs Newton's method iterations until a solution is found */
long double fastforward(exponentiated_number* exp_num, newton_method_instance* newton) {
    int i;
    long double next_;
    for(i = newton->cur_itr; i < newton->max_iterations; ++i) {
        next_ = next(exp_num, newton);
        if(next_ == newton_iteration_statuses[SOLUTION_FOUND]) return newton->x1;
    }
    return newton_iteration_statuses[NaN];
}

int print_next_newton_iteration(long double next_value, newton_method_instance newton)
{
    if(next_value == newton_iteration_statuses[SOLUTION_FOUND]) {
        printf("After %3d iterations, root = %8.6Lf\n", newton.cur_itr, newton.x1);
    } else if(next_value == newton_iteration_statuses[INF] || next_value == newton_iteration_statuses[NaN]) {
        printf("sorry won't work\n"); 
    } else {
        printf("   At Iteration no. %3d, x = %9.6Lf\n", newton.cur_itr, next_value);
        return 1;
    }

    return 0;
}