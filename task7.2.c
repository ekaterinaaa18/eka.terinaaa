#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
void task2(void){
    int mas[] = {5, 112, 4, 3};
    int N = sizeof(mas)/sizeof(mas[0]);
    for(int i=N-1;i>=0;i--){
        printf("%d\t", mas[i]);
        
    }
}
int main(void){
    task2();
}
