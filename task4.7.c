#include <stdio.h>
#include <math.h>

double series(int n, double x) {
    double x_i = 1.;
    double s = 1.;

    for (int i = 1; i <= n; i++) {
        x_i *= x;
        x_i /= i;
        s += x_i;
    }

    return s;
}

int main(void) {
    printf("%.18lf\n", exp(1.) - series(100, 1.));

    double x;
    int n;
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%lf", &x);

    printf("%.18lf\n", series(n, x));
}
