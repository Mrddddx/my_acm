#include<bits/stdc++.h>
using namespace std;
int road[31][31];
int p[31];
int ans[31];
struct st
{
    int bef=-1;
    int v;
} f[31];
int main()
{
    int n,t=1;//t是表示最多地雷数路线的终点
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i],f[i].v=p[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            cin>>road[i][j];
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        if(road[i][j]==1) 
            if(f[j].v<f[i].v+p[j]) 
            {
                f[j].v=f[i].v+p[j],f[j].bef=i;
                
            }
            if(f[j].v>f[t].v) t=j;
    }
    int num=0;
    int a=t;
    while(t!=-1)
    {
        ans[++num]=t;
        t=f[t].bef;
    }
    for(int i=num;i>=1;i--)
        cout<<ans[i]<<' ';
    cout<<'\n'<<f[a].v;
    system("pause");
    return 0;
}