//Вариант 9. Катаев Степан РИС-26-3б
#include <iostream>
using namespace std;

float FL(float a, float b)//Формула для float
{
    return ((a+b)*(a+b)*(a+b)*(a+b)-(a*a*a*a+4*a*a*a*b))/(6*a*a*b*b+4*a*b*b*b+b*b*b*b);//Возвращаем результат
}

double DB(double a, double b)//формула для double
{
    return ((a+b)*(a+b)*(a+b)*(a+b)-(a*a*a*a+4*a*a*a*b))/(6*a*a*b*b+4*a*b*b*b+b*b*b*b);//Возвращаем результат
}

int main()
{
    float fla=100, flb=0.001;//Задаём float переменные
    double dba=100, dbb=0.001;//Задаём double переменные
    cout << "Float: " << FL(fla, flb) << endl;//Выводим результат формулы для float
    cout << "Double: " << DB(dba, dbb) << endl;//Выводим результат формулы для double
    return 0;
}

/*Объяснение:
Типы float и double занимают разное количество памяти в компьютере из-за чего
у них разная точность. Именно поэтому при больших формулах float накапливает неточность 
и результат может сильно отличатся от double. Double окажется более точным*/