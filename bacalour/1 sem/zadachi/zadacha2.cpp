#include <iostream>
using namespace std;

int main()
{
    int n, p, z = 1;
    cin>>n;
    p = n/2;
    for (int i = 1; i<=((n+1)/2); ++i)
    {
        for (int j = 1; j <= p; ++j)
        {
            cout<<" ";
        }
        for (int j = 1; j <= z; ++j)
        {
            cout<<"*";
        }
        --p;
        z += 2;
        cout<<endl;
    }
    return 0;
}