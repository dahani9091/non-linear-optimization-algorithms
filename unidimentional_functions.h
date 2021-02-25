#pragma once
#ifndef UNIDIMENTIONAL_FUNCTION_H
#define UNIDIMENTIONAL_FUNCTION_H

typedef struct interval_ {
	double a;
	double b;
}interval;

double derivative(double x, double (*f) (double));

#endif 





