#include <stdio.h>
#include <math.h>

// Lab 3 Task 2

int main(void) {
    unsigned n;
    printf("n=");
    scanf("%u", &n);

    //digits
    //n = n0 + n1 * 10 + n2 * 100
    unsigned n0 = n % 10;
    n /= 10;
    unsigned n1 = n % 10;
    n /= 10;
    unsigned n2 = n;

    if (n0 == n1 || n1 == n2) {
        puts("digits repetition detected");
        return 0;
    }

    printf(
        "ditigts permut: %d%d%d, %d%d%d, %d%d%d, %d%d%d, %d%d%d, %d%d%d\n",
        n0, n1, n2,
        n0, n2, n1,
        n1, n0, n2,
        n1, n2, n0,
        n2, n0, n1,
        n2, n1, n0
    );
}
