#include <stdio.h>

int main(void) {
    unsigned a, b, c;
    //a) a,b,c < 2^10
    scanf("%u,%u,%u", &a, &b, &c);
    printf("a) %u\n", a * b * c);

    unsigned long long d, e, f;
    //b) d,e,f < 2^20
    scanf("%llu,%llu,%llu", &d, &e, &f);
    printf("b) %llu\n", d * e * f);
}
