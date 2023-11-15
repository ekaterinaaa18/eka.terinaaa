#include <stdio.h>
#include <math.h>

double calc_poly(int n, double x) {
    double x_pow = 1., sum = 0.;
    for (int i = 1; i <= n; i++) {
        x_pow *= x;
        sum += i * x_pow;
    }
    return sum;
}

int main(void) {
    int n;
    double x;
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%lf", &x);

    printf("P(%d, %lf) = %lf\n", n, x, calc_poly(n, x));
}
