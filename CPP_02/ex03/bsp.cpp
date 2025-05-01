#include "Point.hpp"


static float area(Point const p1, Point const p2, Point const p3){
    float area = std::abs(
        p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
        p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
        p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())
    ) / 2.0f;
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    (void)point;
    float ABC = area(a, b, c);
    float PAB = area(a, b, point);
    float PAC = area(a, c, point);
    float PCB = area(b, c, point);

    if (PAB == 0.0f || PAC == 0.0f || PCB == 0.0f)
        return false;
    if (ABC == PAB + PAC + PCB)
        return true;
    return false;
}