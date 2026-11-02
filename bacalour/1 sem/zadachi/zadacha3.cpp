#include <iostream>
using namespace std;

int main()
{
    int n, k = 1, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= 2*i; ++j)
        {
            k *= j;
        }
        s += k;
        k = 1;
    }
    cout << s;
    return 0;
}