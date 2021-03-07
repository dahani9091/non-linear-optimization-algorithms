#pragma once
#ifndef MULTIDIMENTIONAL_FUNCTION_H
#define MULTIDIMENTIONAL_FUNCTION_H

/********************* 1- Gradient descent ********************/

double* gradient_descent(double* x0_vector, double tol, double (*f)(int, double*), int n);

//gradient operator
double* gradientOp(int n, double* vector, double (*f)(int, double*));
// to calculate partial derivative
double partial_derivative(int n, double* vector, int index, double (*f)(int, double*));
// Euclidean Norm
double Norm(int n, double* vector);



/**** to find alpha *****/
// g(alpha,xk,f) = f(  xk - alpha gradienOp(f(xk))  )
double g(double alpha, double* vector_xk, double (*f)(int, double*), int n);
//methode 1
double newton_for_g(double x0, double tol, double* vector_xk, double (*f)(int, double*), int n);
//methode 2
double* bissect_for_g(double a, double b, double tol, double* vector_xk, double (*f)(int, double*), int n);
//methode 3
double false_position_for_g(double x0, double x1, double tol, double* vector_xk, double (*f)(int, double*), int n);

//helpful functions
double derivative_for_g(double alpha, double* vector_xk, double (*f)(int, double*), int n);
double derivative_nd_for_g(double alpha, double* vector_xk, double (*f)(int, double*), int n);

/** vectors operators **/
// Multiplication of a number and a vector 
double* multi(double coef, double* vector, int n);
// Substraction of two vectors
double* subst(double* vector1, double* vector2, int n);

/*************************************************************/
#endif 

//
