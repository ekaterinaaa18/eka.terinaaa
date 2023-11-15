#include <stdio.h>
#include <math.h>

double func_sin(int n, double x) {
    for (int i = 0; i < n; i++) {
        x = sin(x);
    }
    return x;
}

int main(void) {
    int n;
    double x;
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%lf", &x);
    printf("%lf\n", func_sin(n, x));
}

