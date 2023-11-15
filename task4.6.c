#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    printf("n=");
    scanf("%d", &n);
    // a)
    double a = 0.;
    for (int i = 0; i < n; i++) {
        a = sqrt(a + 2.);
    }

    printf("a) %lf\n", a);

    // b)
    double b = 0.;
    for (int i = 0; i < n; i++) {
        b = sqrt(3*(n-i) + b);
    }

    printf("b) %lf\n", b);
}
