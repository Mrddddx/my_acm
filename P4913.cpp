#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int n;
struct st{
    int left,right;
}tree[1008611];
int dfs(int x)
{
    if(!x) return 0;
    else return max(dfs(tree[x].left),dfs(tree[x].right))+1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tree[i].left>>tree[i].right;
    }
    cout<<dfs(1);
    system("pause");
    return 0;
}