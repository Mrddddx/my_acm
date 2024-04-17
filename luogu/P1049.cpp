#include <bits/stdc++.h> 
using namespace std;
int n;
int f[20202];
int v[20202];
int V;
int main()
{
    cin >> V ;
    cin >> n ;
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    for(int  i = 1; i <= n; i++)
        for(int j = V; j >= 0; j--)
        if (j >= v[i])
            f[j] = max (f[j] , f[j-v[i]] + v[i]);
    cout <<V - f[V];
    system("pause");
    return 0;
}