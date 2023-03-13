#include <iostream>
#include <algorithm>
using namespace std;

// Функция вычисления расстояния между двумя точками для нахождения длин сторон треугольника
double calculateDistance(double* p1, double* p2) {

    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}

// Функция вычисления периметра треугольника по трем точкам
double calculatePerimeter(double* p1, double* p2, double* p3) {
    double a = calculateDistance(p1, p2);
    double b = calculateDistance(p1, p3);
    double c = calculateDistance(p2, p3);

    double maxSide = max({ a, b, c });
    if (a + b + c - maxSide <= maxSide) { // сумма длин двух меньших сторон не должна быть меньше, чем длина наибольшей стороны
        // Невыполнение условия, треугольник не может существовать
        return -1;
    }
    return a + b + c;
}

// Функция для нахождения трех точек, образующих треугольник с наибольшим периметром
double** findLargestTriangle(double** points, int size) {
    double largestPerimeter = 0;

    // largestTriangle - указатель на массив указателей на объекты типа Point // массив указателей на объекты типа Point 
    double** largestTriangle = new double* [3];

    /*
        Перебираем все точки в массиве, кроме последних двух.
        Последние две точки могут использоваться только в комбинации с другими точками
    */
    for (int i = 0; i < size - 2; i++) {

        // Перебираем все точки, начиная со следующей после i-ой точки, и заканчивая предпоследней точкой в массиве.
        for (int j = i + 1; j < size - 1; j++) {

            // Перебираем все точки, начиная со следующей после j-ой точки, и заканчивая последней точкой в массиве.
            for (int k = j + 1; k < size; k++) {
                double perimeter = calculatePerimeter(points[i], points[j], points[k]);
                if (perimeter > largestPerimeter) {
                    if (perimeter != -1) { // проверяем результат на -1
                        largestPerimeter = perimeter;
                        largestTriangle[0] = points[i];
                        largestTriangle[1] = points[j];
                        largestTriangle[2] = points[k];
                    }
                }
            }
        }
    }
    return largestTriangle;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int numPoints;

    cout << "Введите количество точек: ";
    cin >> numPoints;

    if (numPoints < 3)
    {
        cout << "Необходимо минимум 3 точки.";
        return 0;
    }

    // Создаем указатель на массив указателей на значения типа double.
    double** points = new double* [numPoints];

    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        cout << "Введите координаты точки " << i + 1 << ": ";
        cin >> x >> y;
        points[i] = new double[2];
        points[i][0] = x;
        points[i][1] = y;
    }
    
    // { 1, 1 };
    // { 3, 1 };
    // { 2, 3 };
    // { 1, 5 };

    // Находим треугольник с наибольшим периметром
    double** largestTriangle = findLargestTriangle(points, numPoints);

    // Выводим результат
    cout << "Точки, образующие треугольник с наибольшим периметром: " << endl;
    cout << "(" << largestTriangle[0][0] << ", " << largestTriangle[0][1] << "), ";
    cout << "(" << largestTriangle[1][0] << ", " << largestTriangle[1][1] << "), ";
    cout << "(" << largestTriangle[2][0] << ", " << largestTriangle[2][1] << ")" << endl;

    // Освобождаем выделенную память
    delete[] largestTriangle;
    delete[] points;

    return 0;
}
/*
    Это может быть полезным для создания массива, состоящего из других массивов, или для создания массива указателей на объекты, 
    которые могут быть созданы и управляться динамически в программе.

*/