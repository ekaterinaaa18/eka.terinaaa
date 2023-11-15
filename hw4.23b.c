#include <stdio.h>
#include <math.h>

int main(void) {
  int n;
  float y[100], z[100], min;
  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter y[%d]: ", i);
    scanf("%f", &y[i]);
  }

  for (int i = 0; i < n; i++) {
    if (fabs(y[i]) >= 1)
    {
      z[i] = y[i];
    }
    else
    {
      z[i] = 2;
    }
  }

  min = fabs(z[0]);
  for (int i = 0; i < n; i++) {
    if (fabs(z[i]) < min)
    {
      min = fabs(z[i]);
    }
  }

  printf("min(|z_1|, |z_2|, ..., |z_n|) = %f\n", min);
  return 0;
}
