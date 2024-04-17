#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int n,m,p;
int a[120][120];
int b[120][120];
int ud[5]={0,-1,1,0,0},lr[5]={0,0,0,-1,1};
struct st
{
    int xx,yy,zz,ready;
} t,now;
queue<st> q;
int main()
{
    cin>>m>>n;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    t.xx=1,t.yy=1,t.zz=a[1][1];
    q.push(t);
    b[1][1]=0;
    while(!q.empty())
    {
        now=q.front();
        for(int i=0;i<=4;i++)
        {
            if(i==0) now.ready=1;
            int u=now.xx+u[i],l=now.yy+lr[i];
            if(u>m||l>m||u<1||l<1) continue;
            if(b[])
        }
    }
    system("pause");
    return 0;
}
