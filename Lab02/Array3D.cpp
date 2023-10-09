#include "Array3D.h"

Array3D::Array3D(int dim0, int dim1, int dim2)
	: dim0(dim0), dim1(dim1), dim2(dim2), data(new int[dim0 * dim1* dim2]) {}

Array3D::~Array3D()
{
	delete[] data;
}

int& Array3D::operator()(int i, int j, int k)
{
	return data[i * dim1 * dim2 + j * dim2 + k];
}

int* Array3D::GetValues(SliceDimension dimension, int index)
{
    int* slice = nullptr;
    switch (dimension)
    {
    case SliceDimension::First:
        slice = new int[dim1 * dim2];
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                slice[j * dim2 + k] = data[index * dim1 * dim2 + j * dim2 + k];
            }
        }
        break;

    case SliceDimension::Second:
        slice = new int[dim0 * dim2];
        for (int i = 0; i < dim0; i++)
        {
            for (int k = 0; k < dim2; k++)
            {
                slice[i * dim2 + k] = data[i * dim1 * dim2 + index * dim2 + k];
            }
        }
        break;

    case SliceDimension::Third:
        slice = new int[dim0 * dim1];
        for (int i = 0; i < dim0; i++)
        {
            for (int j = 0; j < dim1; j++)
            {
                slice[i * dim1 + j] = data[i * dim1 * dim2 + j * dim2 + index];
            }
        }
        break;
    }
    return slice;
}

void Array3D::SetValuesCoordinate(SliceDimension dimension, int index, int** values)
{
    switch (dimension)
    {
    case SliceDimension::First:
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                (*this)(index, j, k) = values[j][k];
            }
        }
        break;

    case SliceDimension::Second:
        for (int i = 0; i < dim0; i++)
        {
            for (int k = 0; k < dim2; k++)
            {
                (*this)(i, index, k) = values[i][k];
            }
        }
        break;

    case SliceDimension::Third:
        for (int i = 0; i < dim0; i++)
        {
            for (int j = 0; j < dim1; j++)
            {
                (*this)(i, j, index) = values[i][j];
            }
        }
        break;
    }
}

void Array3D::SetValuesCoordinatePair(SlicerRowDimensions dimension, int index1, int index2, int* values)
{
    switch (dimension)
    {
    case SlicerRowDimensions::FirstSecond:
        for (int x = 0; x < dim2; x++)
        {
            (*this)(index1, index2, x) = values[x];
        }
        break;

    case SlicerRowDimensions::FirstThird:
        for (int x = 0; x < dim1; x++)
        {
            (*this)(index1, x, index2) = values[x];
        }
        break;

    case SlicerRowDimensions::SecondThird:
        for (int x = 0; x < dim0; x++)
        {
            (*this)(x, index1, index2) = values[x];
        }
        break;
    }
}

Array3D Array3D::Fill(int dim0, int dim1, int dim2, int value)
{
    Array3D result(dim0, dim1, dim2);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                result(i, j, k) = value;
            }
        }
    }
    return result;
}

Array3D Array3D::Zeros(int dim0, int dim1, int dim2)
{
    return Fill(dim0, dim1, dim2, 0);
}

Array3D Array3D::Ones(int dim0, int dim1, int dim2)
{
    return Fill(dim0, dim1, dim2, 1);
}
