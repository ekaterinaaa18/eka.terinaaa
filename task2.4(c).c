#include <stdio.h>
void variant_v(void){
    double x, y1, y2;
    printf("x = ");
    scanf("%lf", &x);
    y1 = x + 1;
    y2 = y1 * y1;
    double y = y2 * y2 * y1;
    printf("%lf \n", y);
    
}

int main(void) {
    variant_v();
}
