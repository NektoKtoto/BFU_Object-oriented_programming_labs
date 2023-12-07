// Параметры для ввода/вывода по координате
enum class SliceDimension
{
    First,
    Second,
    Third
};

// Параметры для ввода по двум координатам
enum class SlicerRowDimensions
{
    FirstSecond,
    FirstThird,
    SecondThird
};

class Array3D
{
public:
    Array3D(int dim0, int dim1, int dim2);
    ~Array3D();

    int& operator()(int i, int j, int k);

    int* GetValues(SliceDimension dimension, int index);

    void SetValuesCoordinate(SliceDimension dimension, int index, int** values);

    void SetValuesCoordinatePair(SlicerRowDimensions dimension, int index1, int index2, int* values);

    Array3D Fill(int dim0, int dim1, int dim2, int value);
    Array3D Zeros(int dim0, int dim1, int dim2);
    Array3D Ones(int dim0, int dim1, int dim2);

private:
    int dim0,
        dim1,
        dim2;
    int* data;
};
