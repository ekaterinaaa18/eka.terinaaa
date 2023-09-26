#include <stdio.h>
double rosenbrock2d(double x, double y){
    double res1, res2;
    res1 = x * x - y;
    res2 = x - 1;
    return 100. * res1 * res1 + res2 * res2;
}


int main(void) {
    printf("%lf\n", rosenbrock2d(0., 1.));
    printf("%lf\n", rosenbrock2d(1., 1.));
    printf("%lf\n", rosenbrock2d(1., 0.));
}
