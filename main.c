#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "unidimentional_functions.h"
#include "multidimentional_functions.h"



// Function to test Bissection Algorthm.
double phi(double x)
{
    /* We need the expression of the function  */
    return pow(x, 3) + 3 * pow(x, 2) - 1;
}

// Function to test False Position Algorthm.
double phi2(double x)
{
    /* We need the expression of the function  */
    return pow(x, 4) + 2 * pow(x, 2) + 1;
}

double f(int n,double* vector) {
    return pow(4-pow(vector[0],2)-2*pow(vector[1],2),2)  ;
    //return 0.5*(pow(vector[0], 2) + pow(vector[1], 2));
}

int main()
{
    double* vect = (double*)malloc(2 * sizeof(double));
    vect[0] = 0;
    vect[1] = 1;
    double* res = (double*)malloc(2 * sizeof(double));
    res = gradient_descent(vect, 0.001, f, 2);
    double res2 = newton_for_g(0.8, 0.001, vect, f, 2);
    double res1;
    res1 = false_position_for_g(0.5, 1.5, 0.001, vect, f, 2);
    printf("%f %f\n", res[0],res[1]);
   /*
    double* vect = (double*)malloc(2 * sizeof(double));
    vect[0] = 1;
    vect[1] = 2;
    double res ;
   
    res = Norm(2,vect);
    printf("%f \n",res);
    */
    /*
    int choice = 2;
    printf("Choose which algorithm:\n1_ Bissection\n2_ Newton-Raphson\n3_ False Position\n4_ Fibonacci\n");
    printf("Your choice : ");
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        double* var;
        var = (double*)malloc(2 * sizeof(double));
        var = bissect(-1, 1, 0.001, phi);
        printf("Le resultat : %f_%f", var[0], var[1]);
        break;
    }
    case 2:
    {
        double res;
        res = newton(4, phi2, 0.001);
        printf("Le resultat : %f", res);
        break;
    }
    case 3:
    {
        double res2;
        res2 = false_position(0.4, -0.2, phi2, 0.01);
        printf("Le resultat : %f", res2);
        break;
    }
    case 4:
    {
        double* interval;
        interval = (double*)malloc(2 * sizeof(double));
        interval = fibonacci(-1, 1, 6, phi);
        printf("Le resultat : %f_%f", interval[0], interval[1]);
    }
    }
    */
}