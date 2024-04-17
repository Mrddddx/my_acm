#include<bits/stdc++.h>
using namespace std;
const int N=505050;
struct Edge
{
    int to,next;
}edge[2*N];
int head[N*2],cnt;
void init()
{
    for(int i=1;i<2*N;i++)
    {
        edge[i].next=-1;
        head[i] = -1;
    }
    cnt=0;
}
void addedge(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
int fa[N][20],deep[N];
void dfs(int x,int father)
{
    deep[x]=deep[father]+1;
    fa[x][0] = father;
    for(int i=1;(1<<i)<=deep[x];i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=head[x];~i;i=edge[x].next)
        if(edge[i].to!=father) dfs(edge[i].to,x);
}

int LCA(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=19;i>=0;i--)
        if(deep[x]-(1<<i)>=deep[y])
            x=fa[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--)
    if(fa[x][i]!=fa[y][i])
            {x=fa[x][i];y=fa[y][i];}
    return fa[x][0];
}

int main()
{
    init();
    int n,m,root;
    cin>>n>>m>>root;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs(root,0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    system("pause");
    return 0;
}