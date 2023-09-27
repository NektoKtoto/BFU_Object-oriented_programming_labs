class Point
{
public:
    Point();

    Point(float x, float y, float z);

    float getX() const;

    float getY() const;

    float getZ() const;

    Point& operator=(const Point& point);

private:
    float x, y, z;
};
