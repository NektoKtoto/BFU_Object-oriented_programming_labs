#include "Point.h"

Point::Point()
    :x(0), y(0), z(0) {}

Point::Point(float x, float y, float z)
    :x(x), y(y), z(z) {}

float Point::getX() const
{
    return x;
}

float Point::getY() const
{
    return y;
}

float Point::getZ() const
{
    return z;
}

Point& Point::operator=(const Point& point)
{
    x = point.getX();
    y = point.getY();
    z = point.getZ();
    return *this;
}
