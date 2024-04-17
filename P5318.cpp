#include <bits/stdc++.h>
using namespace std;

int b[100086],c[100086];
int n,m;
set <int> q[100086];
queue <int> p;
void solve(int x)
{
    cout<<x<<' ';
    for(int i : q[x])
    if(b[i] == 0)
    {
        
        b[i]=1;  
        solve(i);  
    }
}
int main()
{
    cin>>n>>m; 
    for(int i=1;i<=m;i++) 
    {
        int u,d; 
        cin>>u>>d; 
        q[u].insert(d); 
    }
    b[1]=1; 
    solve(1); 

    cout<<endl;

    p.push(1);
    while(!p.empty())
    {
        int x=p.front(); 
        p.pop(); 
        if(c[x]!=0) continue;
        c[x] = 1;
        cout <<x<<' ';
        for (int i : q[x]) p.push(i);
    }
    system("pause");   
    return 0;
}
