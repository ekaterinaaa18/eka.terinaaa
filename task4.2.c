#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    printf("n=");
    scanf("%d", &n);
    printf("%d! = 1", n);
    for (int i = 2; i <= n; i++) {
        printf("*%d", i);
    }
    printf("\n%d! = %d", n, n);
    for (int i = n-1; i >= 1; i--) {
        printf("*%d", i);
    }
    putchar('\n');
}

