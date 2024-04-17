#include<bits/stdc++.h>
using namespace std;

const int N=50505;
struct Edge
{
    int to,next;
} edge[N<<1];
int head[N],cnt=0;

void init()
{
    for(int i=0;i<N;i++)
    {
        edge[i].next=-1;
        head[i]=-1;
    }
        cnt=0;
    
}
void addedge(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int n;
int d[N];//d[u]是以u为根的子树的结点数量
int ans[N],num=0,maxnum=1e9;

void dfs(int u,int fa)
{
    d[u]=1;
    int tmp=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
        d[u]+=d[v];
        tmp=max(tmp,d[v]);
    }
    tmp=max(tmp,n-d[u]);//与tmp=u的最大连通块的结点数
    if(tmp<maxnum)
    {
        maxnum=tmp;
        num=0;
        ans[++num]=u;
    }
    else if(tmp==maxnum) ans[++num]=u;

}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,0);
    sort(ans+1,ans+1+num);
    for(int i=1;i<=num;i++) printf("%d ",ans[i]);
    system("pause");
    return 0;
}