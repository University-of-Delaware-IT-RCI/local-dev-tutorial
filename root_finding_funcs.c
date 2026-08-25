#include <math.h>
#include <stdio.h>

#include "root_finding_funcs.h"

// A quadratic function with roots at x = 0 and x = 4/3
double quadratic_function(double x)
{
    return x * (x - 4.0/3.0);
}

double quadratic_derivative(double x)
{
    return 2 * x - 4.0/3.0;
}

// A quintic function with one real root that can't be expressed in closed form
// https://en.wikipedia.org/wiki/Galois_theory#A_non-solvable_quintic_example
double quintic_function(double x)
{
    // TODO: Implement f(x) = x^5 - x - 1
    return pow(x, 5) - x - 1;
}

double quintic_derivative(double x)
{
    // TODO: Implement f'(x) = 5x^4 - 1
    return 5 * pow(x, 4) - 1;
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

    double residual = fabs(function(x_root));

    if (verbose) printf("\nStep 0: %.17f\n", x_root);
    
    int iter = 1;
    int max_iter = 10;
    double tol = 1e-15;

    while (residual > tol && iter < max_iter)
    {
        x_root = x_root - function(x_root) / derivative(x_root);

        residual = fabs(function(x_root));

        if (verbose) printf("Step %i: %.17f\n", iter, x_root);

        iter++;
    }

    if (verbose) printf("\n");

    if (verbose && residual > tol)
    {
        printf("Warning: root not found!\n\n");
    }

    return x_root;
}