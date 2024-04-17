#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
struct edge{
    int to,cost;
};
int b[100086],c[100086];
int n,m;
vector<int> q[100086];
queue <int> p;
void solve(int x)
{
    cout<<x<<' ';
    for(int i=0,sz=q[x].size();i<sz;i++)
    if(b[q[x][i]]==0)
    {
        
        b[q[x][i]]=1;    
        solve(q[x][i]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,d;
        cin>>u>>d;
        q[u].push_back(d);
    }
    b[1]=1;
    solve(1);
    cout<<endl;
    p.push(1);
    c[1]=1;
    while(!p.empty())
    {
        int x=p.front();
        cout<<x<<' ';
        for(int i=0,sz=q[x].size();i<sz;i++)
        if(c[q[x][i]]==0)
        {
            c[q[x][i]]=1;  
            p.push(q[x][i]);
        }
        p.pop();
    }
    system("pause");   
    return 0;
}