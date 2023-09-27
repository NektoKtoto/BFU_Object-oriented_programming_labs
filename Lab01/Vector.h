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
    
    //����� � ��������
    Vector operator+(const Vector& vector) const;

    //�������� � ��������
    Vector operator-(const Vector& vector) const;

    //��������� ��������� �������
    Vector revers() const;

    //��������� ���������� �������
    Vector single() const;

    //��������� ����� �������
    float lenght() const;

    //��������� ������������ � ��������
    float scalarMultiplication(const Vector& vector) const;

    //��������� ������������ � ��������
    Vector vectorMultiplication(const Vector& vector) const;

    //��������� ������������ � ���������
    float mixedMultiplication(const Vector& vector1, const Vector& vector2) const;

    //�������� �� �������������� � ��������
    bool collinear(const Vector& vector) const;

    //�������� �� �������������� � ���������
    bool coplanar(const Vector& vector1, const Vector& vector2) const;

private:
    float x, y, z;
};
