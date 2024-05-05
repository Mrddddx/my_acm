#include<bits/stdc++.h>
using namespace std;
long long f[1000000];
int main()
{
    //for(int i = 1; i <= 1e6; i++)
    //    cout << i << ' ';
    cout << endl;

    f[1] = 1;
    f[2] = 1;
    cout << 1 << ' ' << 1 << ' ';
    for(int i = 3; i <= 1e6; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] > 1e12 ) {cout << endl << i; break;} 
        cout << f[i] << ' ';
    }
    system("pause");
    return 0;
}