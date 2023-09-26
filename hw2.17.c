#include <stdio.h>
#include <math.h>

//варіант ж

double invsqrt(double x, double alpha){
    return x / sqrt(1 + alpha * x * x);
}

double invsqrt_derivative(double x, double alpha) {
    return 1 / (sqrt(1 + alpha * x * x) * (1 + alpha * x * x));
}
 
int main(void) {
    double x, alpha;
    printf("Enter x: ");
    scanf("%lf", &x);
    
    printf("Enter alpha: ");
    scanf("%lf", &alpha);
    
    printf("f(x) = %lf\n", invsqrt(x, alpha));
    printf("g(x) = %lf\n", invsqrt_derivative(x, alpha));
    return 0;
}
