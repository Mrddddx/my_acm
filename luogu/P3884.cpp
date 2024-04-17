#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct st{    
    int fat,left,right,dis;
} tree[500];
int b[110];
int a[110];
int n,y;
int maxn,minn;
int ff;
int ww;
void deep(int x,int f)
{
    a[f]++;
    if(a[f]>ww) ww=a[f];
    if(tree[x].left!=0) 
        deep(tree[x].left,f+1);
    if(tree[x].right!=0) 
        deep(tree[x].right,f+1);
    if(ff<f) ff=f;
}
void build(int x,int w)//x代表节点，w代表距离，v代表值，通过b不走回头路
{
    //cout << x << endl;
    b[x]=1;
    if(x==y) 
    {
        cout<<ff<<endl<<ww<<endl;
        cout<<w;
        system("pause");
        exit(0);
    }
    if(b[tree[x].fat]!=1&&tree[x].fat!=0) 
    {
        build(tree[x].fat,w+2); 
    }
    if(b[tree[x].left]!=1&&tree[x].left!=0)
    {
        build(tree[x].left,w+1);
    }
    if(b[tree[x].right]!=1&&tree[x].right!=0)
    {
        build(tree[x].right,w+1);
    }    
}
int main()
{
    int x;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int p,q;
        cin>>p>>q;  
        if(tree[p].left==0) tree[p].left=q;
        else tree[p].right=q;
        tree[q].fat=p;
    }   
    /*for(int i=0;i<=n;i++)
    {
        cout<<tree[i].left<<' '<<tree[i].right<<' '<<tree[i].fat<<endl;
      }*/
    tree[0].fat=0;
    cin>>x>>y;
    deep(1,1);
    b[0]=1;
    build(x,0);
    system("pause");
    return 0;
}