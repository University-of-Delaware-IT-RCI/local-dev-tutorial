#include <math.h>
#include <stdio.h>

#include "root_finding_funcs.h"

int test_quadratic_function()
{
    double tolerance = 1e-16;

    double test_point = 0.5;

    double truth_value = -0.75;
    double test_value  = quadratic_function(test_point);

    double error = fabs(test_value - truth_value) / fabs(truth_value);

    if (error < tolerance)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int test_quadratic_derivative()
{
    double tolerance = 1e-16;

    double test_point = 0.5;

    double truth_value = 1;
    double test_value  = quadratic_derivative(test_point);

    double error = fabs(test_value - truth_value) / fabs(truth_value);

    if (error < tolerance)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int test_quintic_function()
{
    double tolerance = 1e-16;

    double test_point = 2;

    double truth_value = 29;
    double test_value  = quintic_function(test_point);

    double error = fabs(test_value - truth_value) / fabs(truth_value);

    if (error < tolerance)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int test_quintic_derivative()
{
    double tolerance = 1e-16;

    double test_point = 2;

    double truth_value = 79;
    double test_value  = quintic_derivative(test_point);

    double error = fabs(test_value - truth_value) / fabs(truth_value);

    if (error < tolerance)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int test_find_root()
{
    double tolerance = 1e-16;

    // The quadratic we're using for this test has roots at -1 and 1
    double truth_val = 1;

    // If we start at 0.5, we should get the root at 1
    double guess = 0.5;
    int verbose = 0;

    double test_val = find_root(quadratic_function, quadratic_derivative,
                                guess, verbose);

    double error = fabs(test_val - truth_val) / fabs(truth_val);

    if (error < tolerance)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void run_test(int (*test)(), int test_index, int num_tests)
{
    printf("Test %i/%i... ", test_index, num_tests);

    if (test() == 0)
    {
        printf("Passed.\n");
    }
    else
    {
        printf("Failed.\n");
    }
}

int main()
{
    int num_tests = 5;

    int (*tests[])() = {
        test_quadratic_function,
        test_quadratic_derivative,
        test_quintic_function,
        test_quintic_derivative,
        test_find_root
    };

    printf("\n");

    for (int i = 0; i < num_tests; i++)
    {
        run_test(tests[i], i + 1, num_tests);
    }

    printf("\n");

    return 0;
}