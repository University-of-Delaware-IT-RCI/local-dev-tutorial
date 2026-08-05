#include <math.h>
#include <stdio.h>
#include "math_funcs.h"

int main()
{
    double pi  = M_PI;
    double e   = exp(1);
    double phi = (1.0 + sqrt(5.0)) / 2.0;

    printf("\npi  = %f\n", pi);
    printf("e   = %f\n", e);
    printf("phi = %f\n\n", phi);

    printf("Calculating phi + (pi * e) ...\n\n");

    double product = multiply(pi, e);
    double sum = add(phi, product);

    printf("The result is: %f\n\n", sum);

    return 0;
}