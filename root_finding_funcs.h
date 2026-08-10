#ifndef ROOT_FINDING_FUNCS_INCLUDE
#define ROOT_FINDING_FUNCS_INCLUDE

double quadratic_function(double x);
double quadratic_derivative(double x);

double quintic_function(double x);
double quintic_derivative(double x);

double find_root(double (*function)(double), double (*derivative)(double),
                 double initial_guess, int verbose);

#endif