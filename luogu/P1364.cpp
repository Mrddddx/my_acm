#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct st{    
    int val,fat,left,right,dis;
} tree[500500];
int b[110];
int n;
int maxn;
void build(int x,int w,int v)//x代表节点，w代表距离，v代表值，通过b不走回头路
{
    b[x]=1;
    if(b[tree[x].fat]!=1&&tree[x].fat!=0) 
    {
        tree[tree[x].fat].dis+=w*v;
        build(tree[x].fat,w+1,v); 
    }
    if(b[tree[x].left]!=1&&tree[x].left!=0)
    {
        tree[tree[x].left].dis+=w*v;
        build(tree[x].left,w+1,v);
    }
    if(b[tree[x].right]!=1&&tree[x].right!=0)
    {
        tree[tree[x].right].dis+=w*v;
        build(tree[x].right,w+1,v);
    }    
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tree[i].val>>tree[i].left>>tree[i].right;
        tree[tree[i].right].fat=i;
        tree[tree[i].left].fat=i;
    }    
    /*for(int i=1;i<=n;i++)
    {
        cout<<tree[i].left<<' '<<tree[i].right<<' '<<tree[i].fat<<endl;
      }
    tree[0].fat=0;*/
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        b[0]=1;
        build(i,1,tree[i].val);
    }
    maxn=tree[1].dis;
    for(int i=2;i<=n;i++)
    maxn=min(tree[i].dis,maxn);
    cout<<maxn;
    system("pause");
    return 0;
}