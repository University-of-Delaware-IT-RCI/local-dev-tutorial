#include <math.h>
#include <stdio.h>
#include "math_funcs.h"

int test_add()
{
    double tol = 1e-14;

    double truth_value = 5;

    double test_value = add(1.5, 3.5);

    double relative_error = fabs(test_value - truth_value) / fabs(truth_value);

    if (relative_error < tol)
        return 1;
    else
        return 0;
}

int test_multiply()
{
    double tol = 1e-14;

    // TODO: Add a truth value
    double truth_value = NAN;

    // TODO: Use implemented multiplication function to get a test value
    double test_value = NAN;

    double relative_error = fabs(test_value - truth_value) / fabs(truth_value);

    if (relative_error < tol)
        return 1;
    else
        return 0;
}

int main()
{
    printf("\nTest 1/2... ");
    if (test_add())
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test 2/2... ");
    if (test_multiply())
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");

    return 0;
}