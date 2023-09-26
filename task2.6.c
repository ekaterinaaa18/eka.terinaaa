#include <stdio.h>
#include <math.h>


double triangle_area(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
    double ab_x = b_x - a_x;
    double ab_y = b_y - a_y;
    double ac_x = c_x - a_x;
    double ac_y = c_y - a_y;

    double area = fabs(ab_x * ac_y - ac_x * ab_y) * 0.5;

    return area;
}

double vector_length(double x, double y) {
    return hypot(x, y);
}

double triangle_area_herone(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
    double ab_x = b_x - a_x;
    double ab_y = b_y - a_y;
    double ac_x = c_x - a_x;
    double ac_y = c_y - a_y;
    double bc_x = c_x - b_x;
    double bc_y = c_y - b_y;

    double ab_len = vector_length(ab_x, ab_y);
    double ac_len = vector_length(ac_x, ac_y);
    double bc_len = vector_length(bc_x, bc_y);

    double p = (ab_len + ac_len + bc_len) * 0.5;

    double area = sqrt(p * (p - ab_len) * (p - ac_len) * (p - bc_len));

    return area;
}

int main(void) {
    double x1, x2, x3;
    double y1, y2, y3;
    printf("x1 = ");
    scanf("%lf", &x1);
    printf("y1 = ");
    scanf("%lf", &y1);
    printf("x2 = ");
    scanf("%lf", &x2);
    printf("y2 = ");
    scanf("%lf", &y2);
    printf("x3 = ");
    scanf("%lf", &x3);
    printf("y3 = ");
    scanf("%lf", &y3);

    printf("area: %lf\n", triangle_area(x1, y1, x2, y2, x3, y3));
    printf("area_herone: %lf\n", triangle_area_herone(x1, y1, x2, y2, x3, y3));
}
