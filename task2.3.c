#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, p, S;
    printf("a = ");
    scanf("%lf", &a);
    
    printf("b = ");
    scanf("%lf", &b);
    
    printf("c = ");
    scanf("%lf", &c);
    
    p = (a + b + c) / 2;
    S = sqrt(p * (p -a) * (p - b) * (p - c));
    printf("S = %lf\n", S);
}
