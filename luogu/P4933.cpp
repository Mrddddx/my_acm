#include<iostream>
#include<cmath>
#include<cstdlib>
#define MAXS 10100
#define MMM 998244353
using namespace std;
int a[MAXS];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cin>>a[i][j];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    maxn=max(maxn,a[n][i]);
    cout<<maxn;
    system("pause");
    return 0;
}