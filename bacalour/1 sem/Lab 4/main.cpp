#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");

    const int N = 100;
    int a[N];
    int n;

    // Ввод реальной длины
    cout << "Введите реальную длину массива (не больше " << N << "): ";
    cin >> n;
    if (n <= 0 || n > N)
    {
        cout << "Некорректная длина массива!" << endl;
    }
    // 2) Печать исходного массива
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // 3) Удаление первого элемента с заданным значением
    int d;
    cout << "Введите значение для удаления: ";
    cin >> d;

    int index = -1;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] == d) 
        {
            index = i;
            break;
        }
    }
    for (int i = index; i < n - 1; i++) 
    {
        a[i] = a[i + 1];
    }
    n--;
    // 4) Циклический сдвиг на K элементов вправо
    int K;
    cout << "Введите K (сдвиг вправо): ";
    cin >> K;

    if (n > 0) {
        K = K % n;
        if (K < 0) K += n;

        if (K != 0) {
            int temp[N];
            for (int i = 0; i < n; i++) {
                temp[(i + K) % n] = a[i];
            }
            for (int i = 0; i < n; i++) {
                a[i] = temp[i];
            }
        }
    }
     // 5) Печать полученного массива
    cout << "Полученный массив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}