#include <iostream>

using namespace std;

//Обыкновенная дробь
struct Fraction {
    int num;   // числитель
    int den;   // знаменатель

    Fraction(int n, int d) : num(n), den(d) {
        if (den == 0) {
            cout << "Ошибка: знаменатель равен 0!\n";
            num = 0; den = 1;
            return;
        }
        // Приводим к несократимому виду (НОД алгоритмом Евклида)
        int a = num < 0 ? -num : num;
        int b = den < 0 ? -den : den;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        int g = a;
        num /= g;
        den /= g;
        // Знак — в числитель
        if (den < 0) { num = -num; den = -den; }
    }

    void print() const { cout << num << "/" << den; }
};

//а) Сложение десятичных дробей
double addFractions(double a, double b) {
    return a + b;
}

//б) Сложение обыкновенных дробей
Fraction addFractions(const Fraction& a, const Fraction& b) {
    return Fraction(a.num * b.den + b.num * a.den, a.den * b.den);
}

//Основная программа
int main() {
    // а) десятичные дроби
    double d1 = 1.25, d2 = 3.75;
    cout << "Сложение десятичных дробей:\n";
    cout << d1 << " + " << d2 << " = " << addFractions(d1, d2) << "\n\n";

    // б) обыкновенные дроби
    Fraction f1(1, 3);
    Fraction f2(2, 5);
    Fraction sum = addFractions(f1, f2);

    cout << "Сложение обыкновенных дробей:\n";
    f1.print(); cout << " + ";
    f2.print(); cout << " = ";
    sum.print(); cout << "\n";

    return 0;
}