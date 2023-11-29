// main.c
#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main() {
    double radius = 5.0;
    double side = 4.0;
    double length = 6.0;
    double width = 3.0;

    printf("Area of Circle with radius %.2f: %.2f\n", radius, getCircleArea(radius));
    printf("Area of Square with side %.2f: %.2f\n", side, getSquareArea(side));
    printf("Area of Rectangle with length %.2f and width %.2f: %.2f\n", length, width, getRectangleArea(length, width));

    return 0;
}
