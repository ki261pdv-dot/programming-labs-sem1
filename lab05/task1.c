#include <stdio.h>
#include <math.h>

int cartesian_to_polar(const double *x, const double *y, double *r, double *phi);

int main(void) {
    double x = 3.0;
    double y = 4.0;
    double radius = 0.0;
    double angle = 0.0;

    printf("Vkhidni dekartovi koordynaty: X = %.2f, Y = %.2f\n", x, y);

    int status = cartesian_to_polar(&x, &y, &radius, &angle);
    if (status == 0) {
        printf("Polyarnyi radius (r): %.4f\n", radius);
        printf("Polyarnyi kut (phi):  %.4f rad\n", angle);
    } else {
        printf("Pomylka: peredano NULL-pokazhchyk!\n");
    }

    return 0;
}

int cartesian_to_polar(const double *x, const double *y, double *r, double *phi) {
    if (x == NULL || y == NULL || r == NULL || phi == NULL) {
        return 1;
    }

    *r = sqrt((*x) * (*x) + (*y) * (*y));
    *phi = atan2(*y, *x);

    return 0;
}
