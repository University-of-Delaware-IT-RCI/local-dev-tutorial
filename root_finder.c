#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "root_finding_funcs.h"

int main(int argc, char *argv[])
{
    // Initial guess for the root location. Defaults to zero.
    double guess = 0;

    // Overwrite default initial guess if one is provided
    if (argc == 2)
    {
        guess = atof(argv[1]);
    }

    int verbose = 1;
    find_root(quintic_function, quintic_derivative, guess, verbose);

    return 0;
}