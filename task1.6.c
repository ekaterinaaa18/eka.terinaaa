#include <stdio.h>

int main(void) {
    float t_c;
    printf("t in C = ");
    scanf("%f", &t_c);
    float t_f = t_c * 9.f / 5.f + 32.f;
    printf("t in F =  %.1f\n", t_f);
}
