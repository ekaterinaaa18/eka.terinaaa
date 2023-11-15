#include <stdio.h>

int main(void) {
    double a, b;
    printf("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);

    if (a < b) {
        double c = a;
        a = b;
        b = c;
    }

    printf("max: %lf\nmin: %lf\n", a, b);
}
