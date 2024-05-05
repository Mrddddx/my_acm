#include<bits/stdc++.h>
using namespace std;
int a[200100];
int t;
int main()
{
    int n, q;
    cin >> q >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] ++;
        if(a[x] & 1) q--;
        else q++;
    }
    cout << q;
    system("pause");
    return 0;
}