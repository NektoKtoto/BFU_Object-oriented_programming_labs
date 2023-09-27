class Point;

class Vector
{
public:
    Vector();

    Vector(float x, float y, float z);
    
    Vector(const Point& start, const Point& end);

    float getX() const;

    float getY() const;

    float getZ() const;

    void print() const;

    Vector& operator=(const Vector& vector);
    
    //сумма с вектором
    Vector operator+(const Vector& vector) const;

    //разность с вектором
    Vector operator-(const Vector& vector) const;

    //получение обратного вектора
    Vector revers() const;

    //получение единичного вектора
    Vector single() const;

    //получение длины вектора
    float lenght() const;

    //скалярное произведение с вектором
    float scalarMultiplication(const Vector& vector) const;

    //векторное произведение с вектором
    Vector vectorMultiplication(const Vector& vector) const;

    //смешанное произведение с векторами
    float mixedMultiplication(const Vector& vector1, const Vector& vector2) const;

    //проверка на коллинеарность с вектором
    bool collinear(const Vector& vector) const;

    //проверка на компланарность с векторами
    bool coplanar(const Vector& vector1, const Vector& vector2) const;

private:
    float x, y, z;
};
