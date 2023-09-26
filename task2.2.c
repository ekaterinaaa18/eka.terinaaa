#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c;
    printf("a = ");
    scanf("%f", &a);
    
    printf("b = ");
    scanf("%f", &b);
    
    c = sqrt(pow(a, 2) + pow(b, 2));
    printf("c = %.2f\n", c);
}
