#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m,p;
int a[120][120];
int b[120][120];
int maxn=100000;
int t;
int ud[5]={0,-1,1,0,0},lr[5]={0,0,0,-1,1};
void dfs(int x,int y,int z)
{
    if(b[x][y]>=maxn) return;
    if(x==m&&y==m) {
        maxn=b[m][m];
    }
    for(int i=1;i<=4;i++)
    {
        int u=x+ud[i],l=y+lr[i];
        
        if(u>m||l>m||u<1||l<1) continue;
        if(b[u][l]>b[x][y])
        {
            
            /*cout<<x<<' '<<y<<endl<<b[x][y];
            system("pause");*/
            t=b[u][l];
            if(a[u][l]==-1)
            {
                b[u][l]=b[x][y]+2;
                dfs(u,l,z);
                b[u][l]=t;
            }
            else
            {
                if(a[u][l]==z)
                {
                    b[u][l]=b[x][y];
                    dfs(u,l,z);
                    b[u][l]=t;

                }
                else 
                {
                    b[u][l]=b[x][y]+1;
                    dfs(u,l,a[u][l]);
                    b[u][l]=t;

                }
            }
        }   
    }
}

int main()
{
    cin>>m>>n;
    memset(a,-1,sizeof(a));
    memset(b,127,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    b[1][1]=0;
    dfs(1,1,a[1][1]);
    cout<<maxn;
    system("pause");
    return 0;
}
/*
5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0
*/