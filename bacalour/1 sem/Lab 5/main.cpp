#include <iostream>
using namespace std;

// Функция вычисления суммы элементов ниже главной диагонали
double sumBelowMainDiagonal(double** matrix, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {   // j < i — элементы ниже главной диагонали
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n;      // количество матриц
    int size;   // размер квадратной матрицы

    cout << "Введите количество матриц n: ";
    cin >> n;
    cout << "Введите размер квадратных матриц: ";
    cin >> size;

    double maxSum = 0.0;
    bool first = true;      // чтобы корректно инициализировать максимум
    int maxIndex = -1;

    for (int k = 0; k < n; ++k) {
        // Выделение памяти под матрицу size x size
        double** matrix = new double*[size];
        for (int i = 0; i < size; ++i)
            matrix[i] = new double[size];

        // Ручной ввод элементов
        cout << "\nВведите элементы матрицы #" << k + 1
             << " (" << size << "x" << size << "):\n";
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cin >> matrix[i][j];

        double s = sumBelowMainDiagonal(matrix, size);
        cout << "Сумма ниже главной диагонали: " << s << "\n";

        // Поиск максимума (первое значение инициализирует максимум)
        if (first || s > maxSum) {
            maxSum = s;
            maxIndex = k;
            first = false;
        }

        // Освобождение памяти
        for (int i = 0; i < size; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }

    cout << "\nМаксимальная сумма = " << maxSum
         << " (матрица #" << maxIndex + 1 << ")\n";

    return 0;
}