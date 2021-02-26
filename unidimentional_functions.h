#pragma once
#ifndef UNIDIMENTIONAL_FUNCTION_H
#define UNIDIMENTIONAL_FUNCTION_H


double derivative(double x, double (*f)(double));
double derivative_nd(double x, double (*f)(double));
double* bissect(double a, double b, double tol, double (*f)(double));
double newton(double x0, double (*f)(double), double tol);
double false_position(double x0, double x1, double (*f)(double), double tol);
//typedef struct interval_ {
//	double a;
//	double b;
//}interval;
//
//double derivative(double x, double (*f) (double));

#endif 





