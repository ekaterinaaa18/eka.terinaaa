#include <stdio.h>

int main(void) {
    float a, b, c, d;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    c = a - b;
    d = a * b;
    printf("a - b = %.2f\n", c);
    printf("a * b = %.2f\n", d);
}
