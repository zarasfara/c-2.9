#include <iostream>
using namespace std;


// Структура Point, которая будет представлять точку на плоскости.
struct Point {
    double x;
    double y;
};

// Функция вычисления расстояния между двумя точками для нахождения длин сторон треугольника
double calculateDistance(Point* p1, Point* p2) {
    // формула
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Функция вычисления периметра треугольника по трем точкам
double calculatePerimeter(Point* p1, Point* p2, Point* p3) {
    double a = calculateDistance(p1, p2);
    double b = calculateDistance(p1, p3);
    double c = calculateDistance(p2, p3);
    return a + b + c;
}

// Функция для нахождения трех точек, образующих треугольник с наибольшим периметром
Point** findLargestTriangle(Point** points, int size) {
    double largestPerimeter = 0;

    // largestTriangle - указатель на массив указателей на объекты типа Point // массив указателей на объекты типа Point 
    Point** largestTriangle = new Point*[3];
    // перебираем все точки в массиве, кроме последних двух.
    // последние две точки могут использоваться только в комбинации с другими точками
    for (int i = 0; i < size - 2; i++) {
        // Перебираем все точки, начиная со следующей после i-ой точки, и заканчивая предпоследней точкой в массиве.
        for (int j = i + 1; j < size - 1; j++) {
            // перебираем все точки, начиная со следующей после j-ой точки, и заканчивая последней точкой в массиве.
            for (int k = j + 1; k < size; k++) {
                double perimeter = calculatePerimeter(points[i], points[j], points[k]);
                if (perimeter > largestPerimeter) {
                    largestPerimeter = perimeter;
                    largestTriangle[0] = points[i];
                    largestTriangle[1] = points[j];
                    largestTriangle[2] = points[k];
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

    // Создаем массив указателей на структуры Point
    Point** points = new Point * [numPoints];

    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        cout << "Введите координаты точки " << i + 1 << ": ";
        cin >> x >> y;
        points[i] = new Point{ x, y };
    }
    
    //Point p1 = { 1, 1 };
    //Point p2 = { 3, 1 };
    //Point p3 = { 2, 3 };
    //Point p4 = { 1, 5 };

    // Находим треугольник с наибольшим периметром
    Point** largestTriangle = findLargestTriangle(points, numPoints);

    // Выводим результат
    cout << "Точки, образующие треугольник с наибольшим периметром: " << endl;
    cout << "(" << largestTriangle[0]->x << ", " << largestTriangle[0]->y << "), ";
    cout << "(" << largestTriangle[1]->x << ", " << largestTriangle[1]->y << "), ";
    cout << "(" << largestTriangle[2]->x << ", " << largestTriangle[2]->y << ")" << endl;

    // Освобождаем выделенную память
    delete[] largestTriangle;
    return 0;
}

/*
    Point** points

    Эта строка объявляет переменную "points" типа "указатель на указатель на объект класса Point" в C++.

    Тип "указатель на указатель" используется, когда необходимо создать указатель на массив указателей, 
    как в примере выше, где "points" является массивом указателей на объекты класса "Point".

    "Point" в данном случае - это пользовательский тип данных, определенный как класс. 
    Он содержит координаты точки в двумерном пространстве.
*/