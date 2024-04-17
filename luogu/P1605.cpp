#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[20][20];//模拟迷宫
int n,m,T;//长和宽
int b[20][20];//模拟路径
int ud[5]={0,1,-1,0,0},lr[5]={0,0,0,1,-1};//定义上下左右
struct st
{
    int x,y;
} ;
st s,e;//起点，终点，交换器
int ans;
void search(int p,int q)
{
    if(p==e.x&&q==e.y) 
    {
        ans++;
        return;
    }
    int u,l,t;
    
    for(int i=1;i<=4;i++)
    {
        u=p+ud[i],l=q+lr[i];
        if(u<1||l<1||u>n||l>m) continue;
        if(a[u][l]==-1)
        {
            a[u][l]=1;
            search(u,l);
            a[u][l]=-1;
        }
    }
}
int main()
{
    memset(a,-1,sizeof(a));//初始化
    memset(b,-1,sizeof(b));
    cin>>n>>m>>T;
    cin>>s.x>>s.y>>e.x>>e.y;
    for(int i=1;i<=T;i++)
    {
        int Tx,Ty;
        cin>>Tx>>Ty;
        a[Tx][Ty]=1;
    }
    a[s.x][s.y] = 1;  
    search(s.x,s.y);
        ///////////////////////////////////小检查
    /*   for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cout<<b[i][j]<<"  ";
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
*/
        ///////////////////////////////////
    cout<<ans;
    system("pause");
    return 0;
}