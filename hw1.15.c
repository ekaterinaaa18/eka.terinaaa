#include <stdio.h>
#include <math.h>
int main(){
    double m, v, E;
    printf("m = ");
    scanf("%lf", &m);
    
    printf("v = ");
    scanf("%lf", &v);
    
    E = (m * pow(v, 2)) / 2;
    printf("E = %lf\n", E);
    
}
