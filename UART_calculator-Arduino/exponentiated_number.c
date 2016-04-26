#include <math.h>

#include "exponentiated_number.h"

void init_exponentiated_number(exponentiated_number* exp_num, long double base, long double exponent)
{
    long long gcd_ = gcd(round(exponent * POWER_CONVERSION_PRECISION), POWER_CONVERSION_PRECISION);
    exp_num->base = base;
    exp_num->power_numerator = round(exponent * POWER_CONVERSION_PRECISION) / gcd_;
    exp_num->power_denominator = POWER_CONVERSION_PRECISION / gcd_;
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