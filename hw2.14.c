#include <stdio.h>
#include "math.h"
void task2_14(void){
    float a, b, c, x1, x2, d;
    printf("a = ");
    scanf("%f", &a);
    
    printf("b = ");
    scanf("%f", &b);
    
    printf("c = ");
    scanf("%f", &c);
    
    d = b * b - 4 * a * c;
    if(d<0){
        printf("No roots");
    }
    else{
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %f\nx2 = %f\n", x1, x2);
    }
}
int main(void) {
    task2_14();
}
