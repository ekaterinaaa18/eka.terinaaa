#include <stdio.h>

int main(void) {
    double x;
    printf("x = ");
    scanf("%lf", &x);
    
    double y;
    // a) x^4 | 2
    y = x * x; //x^2
    y = y * y; //x^4
    printf("y = %lf\n", y);
    
    // б) x^6 | 3
    y = x * x * x; //x^3
    y = y * y; //x^6
    printf("y = %lf\n", y);
    
    // в) x^9 | 4
    y = x * x * x; //x^3
    y = y * y * y; //x^9
    printf("y = %lf\n", y);
    
    // г) x^15 | 5
    double z;
    z = x * x * x; //x^3
    y = z * z; //x^6
    y = y * y; //x^12
    y = y * z; //x^15
    printf("y = %lf\n", y);
    
    
    // д) x^28 | 6
    double d;
    y = x * x; //x^2
    z = y * y; //x^4
    d = z * z * z; //x^12
    y = d * d * z; //x^28
    printf("y = %lf\n", y);
    
    // е) x^64 | 6
    y = x * x; //x^2
    y = y * y; //x^4
    y = y * y; //x^8
    y = y * y; //x^16
    y = y * y; //x^32
    y = y * y; //x^64
    printf("y = %lf\n", y);
}
