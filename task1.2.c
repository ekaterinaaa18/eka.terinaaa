#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
    double a = 1e-4;
    double b = 24.33e5;
    double c = M_PI;
    double d = M_E;
    double e = sqrt(5.);
    double f = log(100.);

    printf("%.2lf\n ", a);
    printf("%.2lf\n ", b);
    printf("%.2lf\n ", c);
    printf("%.2lf\n ", d);
    printf("%.2lf\n ", e);
    printf("%.2lf\n ", f);
}
