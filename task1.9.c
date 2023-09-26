#include <stdio.h>

int main(void) {
    float a, b;
    printf("a, b = ");
    scanf("%f %f", &a, &b);
    float av = (a + b) / 2.;
    float h = 2. / (1. / a + 1. / b);

    printf("av = %f\nh = %f\n", av, h);

    printf("\nav = %e\nh = %e\n", av, h);
}
