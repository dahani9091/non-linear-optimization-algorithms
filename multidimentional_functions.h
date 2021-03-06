#pragma once
#ifndef MULTIDIMENTIONAL_FUNCTION_H
#define MULTIDIMENTIONAL_FUNCTION_H

//multi
double* gradientOp(int n, double* vector, double (*f)(int, double*));
double partial_derivative(int n, double* vector, int index, double (*f)(int, double*));

#endif 