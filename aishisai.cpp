#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
bool b[N];
int ans, n;
int gcd(int y, int x)
{
    return x ? gcd(x, y % x) : y;
}

int main()
{
    b[1] = 1;
    cin >> n;
    for(int i = 2; i * i <= N; i++)
    {
        if(b[i] == 1) continue;
        for(int j = i * i; j * j <= N; j += i)
            b[j] = 1;
    }
    /*for(int i = 2; i * i <= N; i++)
    if(b[i] == 0) cout << i << ' ';*/
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= n; j++)
        {
            if(!b[gcd(j,i)]) 
                ans ++;
               // cout << i << ' ' << j <<"GCD:" << gcd(j,i) << endl;
        }
    cout << ans;
    system("pause");
    return 0;
}
