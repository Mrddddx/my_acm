#include<bits/stdc++.h>
using namespace std;
int a[10086];
int level[10086];
int sum[10086];
int lev;
int main()
{

    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+i;
        level[lev++]=sum[i];
        if(sum[i]>n) break;
    }
    for(int i=0;i<lev;i++)
    {
        cout<<level[i]<<' ';
    }
    for(int)
    system("pause");
    return 0;
}