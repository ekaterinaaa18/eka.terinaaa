#include <stdio.h>
#include <math.h>

double polinom(int x, int n) {
    double y = 0;
  for (int i = 0; i <= n; i++) {
        y += pow(x, pow(3, i));
  }
    return y-1;
}

int main() {
    int x, n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%d", &x);
    printf("y = %f\n", polinom(x, n));
    return 0;
}
