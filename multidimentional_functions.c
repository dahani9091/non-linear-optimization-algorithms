#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "multidimentional_functions.h"


//
/*
   notes :
   n is the dimention of IR^n.
   use the mathematical indexing in inputs. like {x1,x2,x3.....} and not {x0,x1...}.
*/

double* gradient_descent(double* x0_vector,double tol,double (*f)(int, double*),int n ) {
    double* min = (double*)malloc(n * sizeof(double*));
    double* xk_prev = (double*)malloc(n * sizeof(double*));
    double* xk_next = (double*)malloc(n * sizeof(double*));
    xk_prev = multi(100, x0_vector, n);
    xk_next = x0_vector;
    double alpha_k;
    while ((Norm(n, gradientOp(n, xk_prev, f)) > tol) || (Norm(n, subst(xk_prev, xk_next, n)) > tol)) {
        alpha_k = false_position_for_g(0, 1.5, 0.0001, xk_prev, f, n);

        xk_prev = xk_next;
        xk_next = subst(xk_prev , multi(alpha_k , gradientOp(n, xk_prev, f),n),n);
        
    } 
    min = xk_next;
    printf("%f\n", f(n,min));
    return min;
}




/**  gradient operator and some useful functions  ****/

//gradient operator

double* gradientOp(int n, double* vector, double (*f)(int,double*)) {
    double* gradient_of_vector = (double*)malloc(n * sizeof(double*));
    int i;
    for (i = 0; i < n; i++) {
        gradient_of_vector[i] = partial_derivative(n, vector, i + 1, f);   // mathematical indexing 
    }
    return gradient_of_vector;
}

//partial derivative
double partial_derivative(int n, double* vector, int index, double (*f)(int ,double*)) {  // index in {1,2,....,n} , mathematical indexing (x1 , x2 , .... xn)
    double* new_vector = (double*)malloc(n * sizeof(double*));
    double partial_derivative_of_vector ;
    double h = 0.00001;
    int i;
    // update X_(index)
    for (i = 0; i < n; i++) {
        if (i == index-1) {
            new_vector[i] = vector[i] + h;
        }
        else {
            new_vector[i] = vector[i];
        }
       
    }
    partial_derivative_of_vector = ((*f)(n, new_vector) - (*f)(n, vector)) / h;

    return partial_derivative_of_vector;
}

// Euclidean norm
double Norm(int n, double* vector) {
    double norm = 0;
    int i;
    for (i = 0; i < n; i++) {
        norm += pow(vector[i], 2);
    }
    return sqrt(norm);
}

/***************************** to find alpha  ***************************************/


double g(double alpha, double* vector_xk, double (*f)(int, double*), int n) {  // g(alpha,xk,f) = f(  xk - alpha gradienOp(f(xk))  )
    double* yk = (double*)malloc(n * sizeof(double*));
    yk = multi(alpha, gradientOp(n, vector_xk, f), n);
    return (*f)(n, subst(vector_xk, yk, n));
}

// methode 1
double newton_for_g(double x0, double tol,  double* vector_xk, double (*f)(int, double*), int n) {
    double alpha_bef;
    double alpha_prev = x0;
    double d;
    do {
        if (derivative_for_g(alpha_prev,vector_xk ,f,n) != 0) {
            d = -(derivative_for_g(alpha_prev, vector_xk, f, n) / derivative_nd_for_g(alpha_prev, vector_xk, f, n));
            alpha_bef = alpha_prev;
            alpha_prev = alpha_bef + d;

        }
        else {
            printf("f''(x) = 0 !! newton is not working in this case\n");
            return alpha_prev;
        }


    } while ((fabs(alpha_prev - alpha_bef) > tol) || (fabs(derivative_for_g(alpha_prev, vector_xk, f, n)) > tol));
    return alpha_prev;
}

// methode 2
double* bissect_for_g(double a, double b, double tol, double* vector_xk, double (*f)(int, double*), int n)
{
    double* res;
    double c;
    res = (double*)malloc(2 * sizeof(double));


    if (!((a < b) && (derivative_for_g(a, vector_xk, f, n) <= 0) && (derivative_for_g(b, vector_xk, f, n) >= 0)))
    {
        printf("Something is wrong!");
        return NULL;
    }

    while (fabs(b - a) > tol)
    {
        c = (a + b) / 2;
        if ((derivative_for_g(c, vector_xk, f, n) == 0) && (derivative_nd_for_g(c, vector_xk, f, n) > 0))
        {
            res[0] = c;
            res[1] = c;
            printf("stop cond\n");
            return res;
        }
        else if (derivative_for_g(c, vector_xk, f, n) <= 0)
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

// methode 3
double false_position_for_g(double x0, double x1,double tol , double* vector_xk, double (*f)(int, double*), int n) {
    double x_prev = x0;
    double x_next = x1;
    double d;
    while ((fabs(x_next - x_prev) > tol) || (fabs(derivative_for_g(x_next, vector_xk, f, n)) > tol)) {
        d = -derivative_for_g(x_next, vector_xk, f, n) * ((x_next - x_prev) / (derivative_for_g(x_next, vector_xk, f, n) - derivative_for_g(x_prev, vector_xk, f, n)));
        x_prev = x_next;
        x_next = x_prev + d;
    }
    return x_next;
}

/** helpful function  **/

double derivative_for_g(double alpha, double* vector_xk, double (*f)(int, double*), int n)
{
    double eps = 0.00000001;
    double res;
    res = ((*g)(alpha + eps, vector_xk,f,n) - (*g)(alpha,vector_xk, f, n)) / eps;  //the definition of the limit
    return res;
}

double derivative_nd_for_g(double alpha, double* vector_xk, double (*f)(int, double*), int n)
{
    double eps = 0.00000001;
    double res;
    res = (derivative_for_g((alpha + eps), vector_xk, f, n) - derivative_for_g(alpha, vector_xk, f, n)) / eps; 
    return res;
}

/******  vectors operators  ********/

// Multiplication of a number and a vector 

double* multi(double coef, double* vector, int n)
{
    double* new_vector = (double*)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        new_vector[i] = vector[i] * coef;
    }
    return new_vector;
}

// Substraction of two vectors 
double* subst(double* vector1, double* vector2, int n)
{
    double* new_vector = (double*)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        new_vector[i] = vector1[i] - vector2[i];
    }
    return new_vector;
}
