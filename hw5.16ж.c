#include <stdio.h>
#include <math.h>

int main(void) {
    float x, eps;
    printf("Input x and eps: ");
    scanf("%f %f", &x, &eps);

    if (x <= -1 || x >= 1) {
        printf("Error: x must be in (-1, 1)\n");
        return 1;
    }

    float ak = x;
    float sk = 0.0;
    int k = 1;

    while (fabsf(ak) >= eps) {
        sk += ak;
        k++;
        ak = ak * (x * x) * (2 * k - 3) / (2 * k - 1);
    }

    float y = 2 * sk;

    printf("ln((1+%f)/(1-%f)) with accuracy %f is %f\n", x, x, eps, y);
    return 0;
}
