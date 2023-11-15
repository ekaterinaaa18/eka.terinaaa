#include <stdio.h>
#include <math.h>

int main(void)
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  double a = 1, b = 1, p = 1;
  for (int k = 2; k <= n; k++)
  {
    a = sqrt(b) + a;
    b = 2 * b + 5 * pow(a, 2);
    p *= a * b;
  }

  printf("P = %lf\n", p);

  return 0;
}
