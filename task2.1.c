#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y;
    printf("x = ");
    scanf("%lf", &x);
    
    y = cosh(x);
    printf("Y = %lf\n", y);
    
}
