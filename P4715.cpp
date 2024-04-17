#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n;
int v[10086],win[10086];
void dfs(int x)
{
    if(x>=1<<n)
    return;
    else 
    {
        dfs(2*x);
        dfs(2*x+1);
        int l=v[2*x],r=v[2*x+1];
        if(l>r){
            v[x]=l;
            win[x]=win[x*2];
        }
        else
        {
            v[x]=r;
            win[x]=win[x*2+1];
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=(1<<n);i++)
    {
        cin>>v[i-1+(1<<n)];
        win[i-1+(1<<n)]=i;
    }
    dfs(1);
    if(v[2]>v[3]) cout<<win[3];
    else cout<<win[2];
    system("pause");
    return 0;
}