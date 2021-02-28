#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "unidimentional_functions.h"




double derivative(double x, double (*f)(double))
{
    double eps = 0.00000001;
    double res;
    res = ((*f)(x + eps) - (*f)(x)) / eps; // Equivalent de la limite.
    return res;
}

double derivative_nd(double x, double (*f)(double))
{
    double eps = 0.00000001;
    double res;
    res = (derivative((x + eps), f) - derivative(x, f)) / eps; // Equivalent de la limite.
    return res;
}

double* bissect(double a, double b, double tol, double (*f)(double))
{
    double* res;
    double c;
    res = (double*)malloc(2 * sizeof(double));


    if (!((a < b) && (derivative(a, f) <= 0) && (derivative(b, f) >= 0)))
    {
        printf("Something is wrong!");
        return NULL;
    }

    while (fabs(b - a) > tol)
    {
        c = (a + b) / 2;
        if (derivative(c, f) == 0 && derivative_nd(c, f) > 0)
        {
            res[0] = c;
            res[1] = c;
            return res;
        }
        else if (derivative(c, f) <= 0)
        {

            a = c;
        }
        else
        {

            b = c;
        }
    }

    res[0] = a;
    res[1] = b;
    return res;
}



double newton(double x0, double (*f)(double), double tol)
{
    double x_bef;
    double x_prev = x0;
    double d;
    do {
        if (derivative_nd(x_prev, f) != 0) {
            d = -(derivative(x_prev, f) / derivative_nd(x_prev, f));
            x_bef = x_prev;
            x_prev = x_bef + d;

        }
        else {
            printf("f''(x) = 0 !! newton is not working in this case\n");
            return x_prev;
        }


    } while ((fabs(x_prev - x_bef) > tol) || (fabs(derivative(x_prev, f)) > tol));
    return x_prev;
}



double false_position(double x0, double x1, double (*f)(double), double tol) {
    double x_prev = x0;
    double x_next = x1;
    double d;
    while ((fabs(x_next - x_prev) > tol) || (fabs(derivative(x_next, f)) > tol)) {
        d = -derivative(x_next, f) * ((x_next - x_prev) / (derivative(x_next, f) - derivative(x_prev, f)));
        x_prev = x_next;
        x_next = x_prev + d;
    }
    return x_next;
}
double Fn(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    else
        return Fn(n-1) + Fn(n - 2);
}
double* fibonacci(double a, double b, int N, double (*f)(double)) {
    double* interval = (double*)malloc(2 * sizeof(double));;
    double x = a;
    double y = b;
    int k = 1;
    while (k <= N) {
        double Xleft = x + (Fn(N - k) / Fn(N + 2 - k)) * (y - x);
        double Yright = x + (Fn(N + 1 - k) / Fn(N + 2 - k)) * (y - x);
        if ((*f)(Xleft) < (*f)(Yright))
            y = Yright;

        else if ((*f)(Xleft) > (*f)(Yright))
            x = Xleft;

        else{
            y = Yright;
            x = Xleft;
            k++;
        }
        k++;
    }
    //if (fabs(y - x) < (b - a) / Fn(N + 1)) 
     interval[0] = x; interval[1] = y;
     return interval;
    
}

































/*
#include <stdio.h>
#include <stdlib.h>



double* bessect(double a, double b, double tol, double (*f) (double))  
{ 
    /*
    conditions :
    a
    */
/*
}

// helpful functions
double derivative(double x, double (*f) (double))
{
    double tol = 0.00000001;
    double lim;
    lim = ((*f)(x + tol) - (*f)(x)) / tol;
    return lim;
}
*/
