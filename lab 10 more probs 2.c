#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int isPointInRectangle(Point p, Point topLeft, Point bottomRight) {
    return p.x >= topLeft.x && p.x <= bottomRight.x && p.y <= topLeft.y && p.y >= bottomRight.y;
}

int main() {
    Point p1 = {2.0, 3.0};
    Point p2 = {5.0, 7.0};
    Point topLeft = {1.0, 8.0};
    Point bottomRight = {6.0, 2.0};

    printf("Distance between points: %.2f\n", calculateDistance(p1, p2));
    if (isPointInRectangle(p1, topLeft, bottomRight))
        printf("Point (%.2f, %.2f) lies within the rectangle.\n", p1.x, p1.y);
    else
        printf("Point (%.2f, %.2f) does not lie within the rectangle.\n", p1.x, p1.y);

    return 0;
}
