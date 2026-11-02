#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".65001");
    int a, b;
    bool f = true;
    cin >> a;
    if (a != 0)
    {
        cin >> b;
        f = (a<b) && f;
        while ((a != b) && f && (b != 0))
        {
            f = (a<b) && f;
            if (f)
            {
                a = b;
                cin >> b;
            }
        }
        if (f)
        {
            cout << "всё правильно";
        }
        else
        {
        cout << "неправильно";
        }
    }
    else
    {
        cout << "нет элементов";
    }
    return 0;
}