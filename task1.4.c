#include <stdio.h>
 
int main(void) {
    float m1, m2, r, gamma, F;
    gamma = 6.673 * 10e-11;
    printf("Enter m1 = ");
    scanf("%f" , &m1);
    
    printf("Enter m2 = ");
    scanf("%f" , &m2);
    
    printf("Enter r = ");
    scanf("%f" , &r);
    
    F = gamma * ((m1 * m2) / (r * r));
    printf("F = %e\n", F);
    return 0;
}
