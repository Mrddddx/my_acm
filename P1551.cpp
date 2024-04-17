#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,p;
int a[1086];
int b[1086];
int father(int x)
{
    return x==a[x]?x:a[x]=father(a[x]);
}
int main()
{
    do
    {
    cin>>m;
    if(m==0) break;
    cin>>n;
    for(int i=1;i<=1000;i++)
    {
        a[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x,y,u,v;
        cin>>x>>y;
        u=father(x),v=father(y);
        if(v!=u) a[u]=v;
    }
    int ans=0;
    memset(b,0,sizeof(b));
    for(int i=1;i<=m;i++)
    {
        b[father(i)]++;
    }
    for(int i=1;i<=m;i++)
    {
        if(b[i]>=1) ans++;
    }
    cout<<ans-1<<endl;
    }
    while(true);
    system("pause");
    return 0;
}
