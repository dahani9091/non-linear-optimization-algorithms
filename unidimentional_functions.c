#include <stdio.h>
#include <stdlib.h>



double* bessect(double a, double b, double tol, double (*f) (double))  
{ 
    /*
    conditions :
    a
    */

}

// helpful functions
double derivative(double x, double (*f) (double))
{
    double tol = 0.00000001;
    double lim;
    lim = ((*f)(x + tol) - (*f)(x)) / tol;
    return lim;
}
