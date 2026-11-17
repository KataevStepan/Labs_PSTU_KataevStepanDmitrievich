#include <iostream>
#include <clocale>
using namespace std;

// Поиск минимального числа типа int
int min(int a[], int n) {
    int minimum = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < minimum)
            minimum = a[i];
    }

    return minimum;
}

// Поиск минимального числа типа double
double min(double a[], int n) {
    double minimum = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < minimum)
            minimum = a[i];
    }

    return minimum;
}

int main() {
    setlocale(LC_ALL, ".65001");

    int a[] = {12, 5, 8, 3, 10};
    int b[] = {15, 7, 22, 4, 9, 13, 2, 18, 6, 11};

    double c[] = {4.5, 2.3, 8.1, 1.2, 9.7, 3.6,
                  5.4, 7.8, 0.9, 6.2, 2.8, 10.5};

    cout << "Минимум из 5 чисел: " << min(a, 5) << endl;
    cout << "Минимум из 10 чисел: " << min(b, 10) << endl;
    cout << "Минимум из 12 чисел: " << min(c, 12) << endl;

    return 0;
}
