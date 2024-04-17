#include <bits/stdc++.h> 
using namespace std;
int ans;
int a[100];

void dfs(int n , int x) //n代表当前题数,x代表得分
{
    if(x == 100) return;//不算
    if(n == 23) {ans++; return;} //前二十二道题可能的情况
    dfs (n + 1 , x + 10); //答对
    dfs (n + 1 , 0); //答错
}
int main()
{
    /*for(int i=1;i<=1000000000; i++)
    {
        int x = i;
        int t=0;
        while(x)
        {
            a[++t] = x % 10;
            x = x / 10;
        }
        if(t % 2 == 1) {i = i * 10 - 1; continue;}
        int L = 0, R = 0;
        for(int j = 1; j <= t / 2; j++)
            L += a[j],  R += a[t - j + 1];
        if(L == R) ans++;
    }*/
    dfs(1 , 0);

    cout << ans;
    system("pause");
    return 0;
}