#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
void task1(void){
    int mas[] = {4, 345, 23, 77, 89};
    int count = 0;
    
    double d;
    printf("D=");
    scanf("%lf", &d);
    for(int i=0;i<5;i++){
        if(mas[i]<d){
            count++;
        }
    }
    printf("Count = %d\n", count);
}
int main(void){
    task1();
}
