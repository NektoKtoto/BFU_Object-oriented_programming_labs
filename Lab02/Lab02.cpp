#include <iostream>
#include <locale>

#include "Array3D.h"

int main()
{
    std::locale::global(std::locale(""));

    int dim0, dim1, dim2;
    std::cout << "Введите размеры трехмерного массива (dim0 dim1 dim2): ";
    std::cin >> dim0 >> dim1 >> dim2;

    Array3D array(dim0, dim1, dim2);

    // Для примера
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                array(i, j, k) = i + j;
            }
        }
    }

    while (true)
    {
        std::cout << "\nВыберите действие:" << std::endl;

        std::cout << "1. Установить значение по индексам (i, j, k)" << std::endl;

        std::cout << "2. Получить срез по первой координате (i)" << std::endl;
        std::cout << "3. Получить срез по второй координате (j)" << std::endl;
        std::cout << "4. Получить срез по третьей координате (k)" << std::endl;

        std::cout << "5. Установить значения в массиве для первой координаты (i)" << std::endl;
        std::cout << "6. Установить значения в массиве для второй координаты (j)" << std::endl;
        std::cout << "7. Установить значения в массиве для третьей координаты (k)" << std::endl;

        std::cout << "8. Установить значения в массиве для первой и второй координат (i, j)" << std::endl;
        std::cout << "9. Установить значения в массиве для первой и третьей координат (i, k)" << std::endl;
        std::cout << "10. Установить значения в массиве для второй и третьей координат (j, k)" << std::endl;

        std::cout << "11. Заполнить массив единицами" << std::endl;
        std::cout << "12. Заполнить массив нулями" << std::endl;
        std::cout << "13. Заполнить массив заданным значением" << std::endl;

        std::cout << "14. Получить срез по первой и второй координате (i, j)" << std::endl;
        std::cout << "15. Получить срез по первой и третьей координате (i, k)" << std::endl;
        std::cout << "16. Получить срез по второй и третьей координате (j, k)" << std::endl;

        std::cout << "0. Выйти" << std::endl;

        int choice;
        std::cout << "\nДействие: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int i, j, k, value;
            std::cout << "Введите индексы (i j k) и значение: ";
            std::cin >> i >> j >> k >> value;
            array(i, j, k) = value;
            break;
        }

        case 2:
        {
            int index;
            std::cout << "Введите индекс для среза по первой координате (i): ";
            std::cin >> index;
            int* slice = array.GetValuesCoordinate(SliceDimension::First, index);

            // Вывод среза
            std::cout << "Срез по первой координате (i):" << std::endl;
            for (int j = 0; j < dim1; j++)
            {
                for (int k = 0; k < dim2; k++)
                {
                    std::cout << slice[j * dim2 + k] << " ";
                }
                std::cout << std::endl;
            }
            delete[] slice;
            break;
        }

        case 3:
        {
            int index;
            std::cout << "Введите индекс для среза по второй координате (j): ";
            std::cin >> index;
            int* slice = array.GetValuesCoordinate(SliceDimension::Second, index);

            // Вывод среза
            std::cout << "Срез по второй координате (j):" << std::endl;
            for (int i = 0; i < dim0; i++)
            {
                for (int k = 0; k < dim2; k++)
                {
                    std::cout << slice[i * dim2 + k] << " ";
                }
                std::cout << std::endl;
            }
            delete[] slice;
            break;
        }

        case 4:
        {
            int index;
            std::cout << "Введите индекс для среза по третьей координате (k): ";
            std::cin >> index;
            int* slice = array.GetValuesCoordinate(SliceDimension::Third, index);

            // Вывод среза
            std::cout << "Срез по третьей координате (k):" << std::endl;
            for (int i = 0; i < dim0; i++)
            {
                for (int j = 0; j < dim1; j++)
                {
                    std::cout << slice[i * dim1 + j] << " ";
                }
                std::cout << std::endl;
            }
            delete[] slice;
            break;
        }

        case 5:
        {
            int index;
            std::cout << "Введите индекс для установки значений по первой координате (i): ";
            std::cin >> index;

            // Выделяем память для массива значений values
            int** values = new int* [dim1];
            for (int j = 0; j < dim1; j++)
            {
                values[j] = new int[dim2];
            }

            std::cout << "Введите значения для первой координаты (i):" << std::endl;
            for (int j = 0; j < dim1; j++)
            {
                for (int k = 0; k < dim2; k++)
                {
                    std::cout << "Значение для (" << j << ", " << k << "): ";
                    std::cin >> values[j][k];
                }
            }

            array.SetValuesCoordinate(SliceDimension::First, index, values);
            std::cout << "Значения установлены." << std::endl;

            // Освобождаем память, выделенную под values
            for (int j = 0; j < dim1; j++)
            {
                delete[] values[j];
            }
            delete[] values;
            break;
        }

        case 6:
        {
            int index;
            std::cout << "Введите индекс для установки значений по второй координате (j): ";
            std::cin >> index;

            // Выделяем память для массива значений values
            int** values = new int* [dim0];
            for (int i = 0; i < dim0; i++)
            {
                values[i] = new int[dim2];
            }

            std::cout << "Введите значения для второй координаты (j):" << std::endl;
            for (int i = 0; i < dim0; i++)
            {
                for (int k = 0; k < dim2; k++)
                {
                    std::cout << "Значение для (" << i << ", " << k << "): ";
                    std::cin >> values[i][k];
                }
            }

            array.SetValuesCoordinate(SliceDimension::Second, index, values);
            std::cout << "Значения установлены." << std::endl;

            // Освобождаем память, выделенную под values
            for (int i = 0; i < dim0; i++)
            {
                delete[] values[i];
            }
            delete[] values;
            break;
        }

        case 7:
        {
            int index;
            std::cout << "Введите индекс для установки значений по третьей координате (k): ";
            std::cin >> index;

            // Выделяем память для массива значений values
            int** values = new int* [dim0];
            for (int i = 0; i < dim0; i++)
            {
                values[i] = new int[dim1];
            }

            std::cout << "Введите значения для третьей координаты (k):" << std::endl;
            for (int i = 0; i < dim0; i++)
            {
                for (int j = 0; j < dim1; j++)
                {
                    std::cout << "Значение для (" << i << ", " << j << "): ";
                    std::cin >> values[i][j];
                }
            }

            array.SetValuesCoordinate(SliceDimension::Third, index, values);
            std::cout << "Значения установлены." << std::endl;

            // Освобождаем память, выделенную под values
            for (int i = 0; i < dim0; i++)
            {
                delete[] values[i];
            }
            delete[] values;
            break;
        }

        case 8:
        {
            int index1, index2;
            std::cout << "Введите индексы для установки значений по первой и второй координатам (i, j): ";
            std::cin >> index1 >> index2;

            // Выделяем память для массива значений values
            int* values = new int[dim2];

            std::cout << "Введите значения для первой и второй координат (i, j):" << std::endl;
            for (int k = 0; k < dim2; k++)
            {
                std::cout << "Значение для (" << k << "): ";
                std::cin >> values[k];
            }

            array.SetValuesCoordinatePair(SlicerRowDimensions::FirstSecond, index1, index2, values);
            std::cout << "Значения установлены." << std::endl;

            // Освобождаем память, выделенную под values
            delete[] values;
            break;
        }

        case 9:
        {
            int index1, index2;
            std::cout << "Введите индексы для установки значений по первой и третьей координатам (i, k): ";
            std::cin >> index1 >> index2;

            // Выделяем память для массива значений values
            int* values = new int[dim1];

            std::cout << "Введите значения для первой и третьей координат (i, k):" << std::endl;
            for (int j = 0; j < dim1; j++)
            {
                std::cout << "Значение для (" << j << "): ";
                std::cin >> values[j];
            }

            array.SetValuesCoordinatePair(SlicerRowDimensions::FirstThird, index1, index2, values);
            std::cout << "Значения установлены." << std::endl;

            // Освобождаем память, выделенную под values
            delete[] values;
            break;
        }

        case 10:
        {
            int index1, index2;
            std::cout << "Введите индексы для установки значений по второй и третьей координатам (j, k): ";
            std::cin >> index1 >> index2;

            // Выделяем память для массива значений values
            int* values = new int[dim0];

            std::cout << "Введите значения для второй и третьей координат (j, k):" << std::endl;
            for (int i = 0; i < dim0; i++)
            {
                std::cout << "Значение для (" << i << "): ";
                std::cin >> values[i];
            }

            array.SetValuesCoordinatePair(SlicerRowDimensions::SecondThird, index1, index2, values);
            std::cout << "Значения установлены." << std::endl;

            // Освобождаем память, выделенную под values
            delete[] values;
            break;
        }
        
        case 11:
        {
            array.Ones(dim0, dim1, dim2);
            std::cout << "Массив заполнен единицами." << std::endl;
            break;
        }

        case 12:
        {
            array.Zeros(dim0, dim1, dim2);
            std::cout << "Массив заполнен нулями." << std::endl;
            break;
        }

        case 13:
        {
            int value;
            std::cout << "Введите значение для заполнения массива: ";
            std::cin >> value;
            array.Fill(dim0, dim1, dim2, value);
            std::cout << "Массив заполнен значением " << value << "." << std::endl;
            break;
        }

        case 14:
        {
            int index1, index2;
            std::cout << "Введите индексы для среза по первой и второй координатам (i, j): ";
            std::cin >> index1 >> index2;
            int* slice = array.GetValuesCoordinatePair(SlicerRowDimensions::FirstSecond, index1, index2);

            // Вывод среза
            std::cout << "Срез по первой и второй координатам (i, j):" << std::endl;
            for (int x = 0; x < dim2; x++)
            {
                std::cout << slice[x] << " ";
            }
            std::cout << std::endl;

            delete[] slice;
            break;
        }

        case 15:
        {
            int index1, index2;
            std::cout << "Введите индексы для среза по первой и третьей координатам (i, k): ";
            std::cin >> index1 >> index2;
            int* slice = array.GetValuesCoordinatePair(SlicerRowDimensions::FirstThird, index1, index2);

            // Вывод среза
            std::cout << "Срез по первой и третьей координатам (i, k):" << std::endl;
            for (int x = 0; x < dim1; x++)
            {
                std::cout << slice[x] << " ";
            }
            std::cout << std::endl;

            delete[] slice;
            break;
        }

        case 16:
        {
            int index1, index2;
            std::cout << "Введите индексы для среза по второй и третьей координатам (j, k): ";
            std::cin >> index1 >> index2;
            int* slice = array.GetValuesCoordinatePair(SlicerRowDimensions::SecondThird, index1, index2);

            // Вывод среза
            std::cout << "Срез по второй и третьей координатам (j, k):" << std::endl;
            for (int x = 0; x < dim0; x++)
            {
                std::cout << slice[x] << " ";
            }
            std::cout << std::endl;

            delete[] slice;
            break;
        }

        default:
        {
            std::cout << "Неверный выбор. Пожалуйста, выберите существующий пункт меню." << std::endl;
            break;
        }
        }
    }

    return 0;
}
