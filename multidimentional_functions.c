#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "multidimentional_functions.h"



//multi ....

double* gradientOp(int n, double* vector, double (*f)(int,double*)) {
    double* gradient_of_vector = (double*)malloc(n * sizeof(double*));
    int i;
    for (i = 0; i < n; i++) {
        gradient_of_vector[i] = partial_derivative(n, vector, i + 1, f);   // mathematical indexing 
    }
    return gradient_of_vector;
}


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
        printf(" %f \n", new_vector[i]);
    }
    partial_derivative_of_vector = ((*f)(n, new_vector) - (*f)(n, vector)) / h;
   // printf(" %f , %f\n", new_tab[0],new_tab[1]);

    return partial_derivative_of_vector;
}

double norm(int n, double* vector) {

}