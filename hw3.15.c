#include <stdio.h>
#include <math.h>

int main(void) {
    float x, y, r, a, b, c;
    printf("Enter x, y, r, a, b, c: ");
    scanf("%f %f %f %f %f %f", &x, &y, &r, &a, &b, &c);
    float d = fabs(a * x + b * y + c) / sqrt(a * a + b * b);
    float f = (a * x + b * y + c) / sqrt(a * a + b * b);
    if (d > r) {
        printf("No intersection points\n");
    }
    else if (d == r) {
        printf("One intersection point\n");
        printf("x = %f, y = %f\n", x - a * f, y - b * f);
    }
    else {
        printf("Two intersection points\n");
        float x1 = x - a * f + b * sqrt(r * r - d * d) / sqrt(a * a + b * b);
        float y1 = y - b * f - a * sqrt(r * r - d * d) / sqrt(a * a + b * b);
        float x2 = x - a * f - b * sqrt(r * r - d * d) / sqrt(a * a + b * b);
        float y2 = y - b * f + a * sqrt(r * r - d * d) / sqrt(a * a + b * b);
        printf("x1 = %f, y1 = %f\n", x1, y1);
        printf("x2 = %f, y2 = %f\n", x2, y2);
    }
    return 0;
}
