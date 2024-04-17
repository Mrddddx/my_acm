#include<bits/stdc++.h>
using namespace std;
int a[10]={0,1,2,3,5,10,20};
int n,w;
int b[10];
int p[1010];
int f[1010];
int ans;
int main()
{
    for(int i=1;i<=6;i++)
    {
        cin>>b[i];
        for(int j=1;j<=b[i];j++)
            p[++n]=a[i];
        w+=a[i]*b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=w;j>=p[i];j--)
            f[j]+=f[j-p[i]];
    }
    for(int i=1;i<=w;i++)
        if(f[i]) ans++;
        cout<<"Total="<<ans;
    system("pause");
    return 0;
}