#include <math.h>
#include <stdio.h>

#include "root_finding_funcs.h"

// A quadratic function with roots at x = 1 and x = -1
double quadratic_function(double x)
{
    return (x + 1) * (x - 1);
}

double quadratic_derivative(double x)
{
    return 2 * x;
}

// A quintic function with one real root that can't be expressed in closed form
double quintic_function(double x)
{
    // TODO: Implement f(x) = x^5 - x - 1
    return NAN;
}

double quintic_derivative(double x)
{
    // TODO: Implement f'(x) = 5x^4 - 1
    return NAN;
}

// Compute a root of a single-variable function using Newton's method.
//
// The inputs are:
//   - A function pointer to the function whose root is to be computed.
//   - A function pointer to that function's derivative.
//   - An initial guess for the location of the root.
//   - An integer flag which determines whether or not the approximation
//     to the location of the root is printed at each iteration.
//
// The output is the location of the root.
double find_root(double (*function)(double), double (*derivative)(double),
                 double initial_guess, int verbose)
{
    double x_root = initial_guess;

    int iterations = 10;

    if (verbose) printf("\nStep 0: %.17f\n", x_root);

    for (int i = 1; i < iterations; i++)
    {
        x_root = x_root - function(x_root)/derivative(x_root);
        if (verbose) printf("Step %i: %.17f\n", i, x_root);
    }

    if (verbose) printf("\n");

    return x_root;
}