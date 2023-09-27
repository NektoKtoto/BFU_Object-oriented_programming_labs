#include <iostream>
#include <locale>

#include "Point.h"
#include "Vector.h"

int main()
{
    std::locale::global(std::locale(""));
    Vector vectors[3];
    std::cout << "Необходимо ввести 3 ветора:\n"
              << "> Возможны 2 способа ввода: (1) - задать координаты вектора\n"
              << "                            (2) - задать вектор по двум точкам\n";
    for (int number = 0; number < 3; ++number)
    {
        std::cout << "> > Выберите способ задачи " << number + 1 << " вектора: ";
        int mode;
        float x, y, z;
        std::cin >> mode;
        if (mode == 1)
        {
            std::cout << "> > > Введите координаты вектора:\n"
                      << "> > > > x: ";
            std::cin >> x;
            std::cout << "> > > > y: ";
            std::cin >> y;
            std::cout << "> > > > z: ";
            std::cin >> z;
            vectors[number] = Vector(x, y, z);
        }
        else
        {
            Point points[2];
            for (int count = 0; count < 2; ++count)
            {
                std::cout << "> > > Введите координаты " << count + 1 << " точки:\n"
                          << "> > > > x: ";
                std::cin >> x;
                std::cout << "> > > > y: ";
                std::cin >> y;
                std::cout << "> > > > z: ";
                std::cin >> z;
                points[count] = Point(x, y, z);
            }
            vectors[number] = Vector(points[0], points[1]);
        }
    }
    for (int number = 0; number < 3; ++number)
    {
        std::cout << "\nВектор " << number + 1 << ": ";
        vectors[number].print();
    }
    std::cout << "\n\nВыберите действие:\n"
              << "> Возможны 2 способа ввода: (+) - найти сумму векторов\n"
              << "                            (-) - найти разность первого вектора с остальными\n"
              << "                            (r) - найти векторы, обратные исходным\n"
              << "                            (e) - найти единичные векторы, коллинеарные исходным\n"
              << "                            (l) - найти длины векторов\n"
              << "                            (s) - найти скалярное произведение первых двух векторов\n"
              << "                            (v) - найти векторное произведение первых двух векторов\n"
              << "                            (m) - найти смешанное произведение векторов\n"
              << "                            (c) - проверка на коллинеарность первых двух векторов\n"
              << "                            (k) - проверка на компланарность\n"
              << "                            (0) - прекратить выбор действий\n";
    char action;
    do {
        std::cout << "> > Укажите действие: ";
        std::cin >> action;
        Vector vector;
        switch (action) {
        case '+':
            vector = vectors[0] + vectors[1] + vectors[2];
            std::cout << "> > > Сумма векторов: ";
            vector.print();
            std::cout << "\n";
            break;
        case '-':
            vector = vectors[0] - vectors[1] - vectors[2];
            std::cout << "> > > Разность векторов: ";
            vector.print();
            std::cout << "\n";
            break;
        case 'r':
            std::cout << "> > > Обратный для:\n";
            for (int number = 0; number < 3; ++number)
            {
                std::cout << "      - вектора " << number + 1 << ": ";
                vector = vectors[number].revers();
                vector.print();
                std::cout << "\n";
            }
            break;
        case 'e':
            std::cout << "> > > Единичный вектор, коллинеарный:\n";
            for (int number = 0; number < 3; ++number)
            {
                std::cout << "      - вектору " << number + 1 << ": ";
                vector = vectors[number].single();
                vector.print();
                std::cout << "\n";
            }
            break;
        case 'l':
            std::cout << "> > > Длина:\n";
            for (int number = 0; number < 3; ++number)
                std::cout << "      - вектора " << number + 1 << ": " << vectors[number].lenght() << "\n";
            break;
        case 's':
            std::cout << "> > > Скалярное произведение первых двух векторов: " << vectors[0].scalarMultiplication(vectors[1]) << "\n";
            break;
        case 'v':
            vector = vectors[0].vectorMultiplication(vectors[1]);
            std::cout << "> > > Вектороное произведение первых двух векторов: ";
            vector.print();
            std::cout << "\n";
            break;
        case 'm':
            std::cout << "> > > Смешанное произведение векторов: " << vectors[0].mixedMultiplication(vectors[1], vectors[2]) << "\n";
            break;
        case 'c':
            if (vectors[0].collinear(vectors[1])) std::cout << "> > > Первые два вектора коллинеарны\n";
            else std::cout << "> > > Первые два вектора неколлинеарны\n";
            break;
        case 'k':
            if (vectors[0].coplanar(vectors[1], vectors[2])) std::cout << "> > > Векторы компланарны\n";
            else std::cout << "> > > Векторы некомпланарны\n";
            break;
        case '0':
            std::cout << "> > > Выход из режима выбора" << std::endl;
            break;
        default:
            std::cout << "> > > Неверный выбор\n";
            break;
        }
    } while (action != '0');
    return 0;
}
