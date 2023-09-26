#include <stdio.h>

int main(void) {
    int a;
    printf("a = ");
    scanf("%d", &a);

    printf(
        "- %d - %d - %d\n"
        "%d | %d | %d\n"
        "- %d - %d - %d\n",
        a, a, a,
        a, a, a,
        a, a, a
    );
}
