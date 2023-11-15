#include <stdio.h>
#include <math.h>

float ReLu(float x) {
  if (x > 0)
    return x;
  else
    return 0;
}

float ReLuDerivative(float x) {
  if (x > 0)
    return 1;
  if (x < 0)
    return 0;
  else
    printf("Error: ReLuDerivative(0) is not defined\n");
    return NAN;
}

int main(void) {
  float x;
  printf("Enter x: ");
  scanf("%f", &x);
  printf("ReLu(x) = %f\n", ReLu(x));
  printf("ReLuDerivative(x) = %f\n", ReLuDerivative(x));
  return 0;
}
