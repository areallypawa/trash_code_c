#include <stdio.h>
#include <math.h>

double len_side(double x0, double y0, double x1, double y1) {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

double geron_square(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double x1 = 0, y1 = 0;
    double x2 = 3, y2 = 0;
    double x3 = 3, y3 = 3;

    // длины сторон
    double a = len_side(x1, y1, x2, y2);
    double b = len_side(x2, y2, x3, y3);
    double c = len_side(x1, y1, x3, y3);

    // площадь треугольника
    double s_abc = geron_square(a, b, c);

    double x = 1, y = 1;
    while (1) {
        printf("Введите координаты точки (x y):\n");
        scanf("%lf %lf", &x, &y)
        // Прилепил обработчик ввода, можешь его включить
        /*
        if (scanf("%lf %lf", &x, &y) != 2) {
            printf("Ошибка ввода.\n");
            return 1;
        }
        */

        // площади
        // первый треугольник
        double a1 = len_side(x1, y1, x, y);
        double b1 = len_side(x2, y2, x1, y1);
        double c1 = len_side(x, y, x2, y2);
        double s_aoc = geron_square(a1, b1, c1);

        // второй треугольник
        double a2 = len_side(x3, y3, x, y);
        double b2 = len_side(x2, y2, x3, y3);
        double c2 = len_side(x, y, x2, y2);
        double s_boc = geron_square(a2, b2, c2);

        // третий треугольник
        double a3 = len_side(x3, y3, x, y);
        double b3 = len_side(x1, y1, x3, y3);
        double c3 = len_side(x, y, x1, y1);
        double s_aob = geron_square(a3, b3, c3);

        double sum_s = s_aoc + s_boc + s_aob;

        if (fabs(s_abc - sum_s) < 1e-9) {
            printf("True\n");
        }
        else {
            printf("False\n");
        }
        if (x == 0 && y == 0) {
            break;
        }
    }

    return 0;
}
