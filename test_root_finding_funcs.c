#include <math.h>
#include <stdio.h>

#include "root_finding_funcs.h"

int test_quadratic()
{
    double tol = 1e-14;

    double test_point = 0.5;

    double truth_val_function = -0.75;
    double test_val_function  = quadratic_function(test_point);

    double error_function = fabs(test_val_function - truth_val_function) /
                            fabs(truth_val_function);

    double truth_val_derivative = 1;
    double test_val_derivative  = quadratic_derivative(test_point);

    double error_derivative = fabs(test_val_derivative - truth_val_derivative) /
                              fabs(truth_val_derivative);

    if (error_function < tol && error_derivative < tol)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int test_quintic()
{
    double tol = 1e-14;

    double test_point = 2;

    double truth_val_function = 29;
    double test_val_function  = quintic_function(test_point);

    double error_function = fabs(test_val_function - truth_val_function) /
                            fabs(truth_val_function);

    double truth_val_derivative = 79;
    double test_val_derivative  = quintic_derivative(test_point);

    double error_derivative = fabs(test_val_derivative - truth_val_derivative) /
                              fabs(truth_val_derivative);

    if (error_function < tol && error_derivative < tol)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int test_find_root()
{
    double tol = 1e-14;

    double truth_val = 1;

    double guess = 0.5;
    int verbose = 0;
    double test_val = find_root(quadratic_function, quadratic_derivative,
                                guess, verbose);

    double error = fabs(test_val - truth_val) / fabs(truth_val);

    if (error < tol)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("\nTest 1/3... ");
    if (test_quadratic())
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test 2/3... ");
    if (test_quintic())
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test 3/3... ");
    if (test_find_root())
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");

    return 0;
}