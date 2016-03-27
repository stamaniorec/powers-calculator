#ifndef EXPONENTIATED_NUMBER_H
#define EXPONENTIATED_NUMBER_H

typedef struct 
{
    long double base;
    long long power_numerator;
    long long power_denominator;
} exponentiated_number;

#define POWER_CONVERSION_PRECISION 1000

void init_exponentiated_number(exponentiated_number* exp_num, long double base, long double exponent);
long long gcd(long long a, long long b);

#endif