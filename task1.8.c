#include <stdio.h>

int main(void) {
    float a, b;
    printf("a = ");
    scanf("%f", &a);
    
    printf("b = ");
    scanf("%f", &b);
    printf("a-b = %.2f\n", a - b);
    printf("a*b = %.2f\n", a * b);
}
