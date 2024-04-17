#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int INF=2147483647;
struct st{    
    int val,siz,num,left,right;
} tree[500500];
int amount;
void add(int x,int v)
{
    tree[x].siz++;
    if(tree[x].val==v) 
    {
        tree[x].num++;
        return;
    }
    else
        if(tree[x].val>v)
            if(tree[x].left!=0) add(tree[x].left,v);
            else
            {
                amount++;
                tree[x].left=amount;
                tree[amount].siz=tree[amount].num=1;
                tree[amount].val=v;
            }
        else 
            if(tree[x].right!=0) 
            add(tree[x].right,v);
            else
            {
                amount++;
                tree[x].right  =amount;
                tree[amount].siz=tree[amount].num=1;
                tree[amount].val=v;
            }
}
int paiwei(int x,int v)
{
    if(x==0) return 0;
    if(v==tree[x].val) return tree[tree[x].left].siz;
    if(v<tree[x].val) return paiwei(tree[x].left,v);
    return paiwei(tree[x].right,v)+tree[tree[x].left].siz+tree[x].num;
}
int paiweix(int x,int rk)
{
    if(x==0) return INF;
    if(tree[tree[x].left].siz>=rk)
        return paiweix(tree[x].left,rk);
    if(tree[tree[x].left].siz+tree[x].num>=rk) return tree[x].val;
    return paiweix(tree[x].right,rk-(tree[tree[x].left].siz+tree[x].num));
}
int pre(int x,int v,int ans)
{
    if(tree[x].val>=v)
    {
        if(tree[x].left==0)
        return ans;
        return pre(tree[x].left,v,ans);
    }
    else 
    {
        if(tree[x].right==0)
        return tree[x].val;
        return pre(tree[x].right,v,tree[x].val);
    }
}

int nxt(int x,int v,int ans)
{
    if(tree[x].val<=v)
    {
        if(tree[x].right==0)
        return ans;
        return nxt(tree[x].right,v,ans);
    }
    else 
    {
        if(tree[x].left==0)
        return tree[x].val;
        return nxt(tree[x].left,v,tree[x].val);
    }
}
int main()
{
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int op,x;
        cin>>op>>x;
        if(op==1)
        {
            cout<<paiwei(1,x)+1<<endl;
        }
        if(op==2)
        {
            cout<<paiweix(1,x)<<endl;;
        }
        if(op==3) cout<<pre(1,x,-INF)<<endl;
        if(op==4) cout<<nxt(1,x,INF)<<endl;
        if(op==5)
        {
            if(amount==0)
            {
                amount++;
                tree[amount].siz=tree[amount].num=1;
                tree[amount].val=x;
            }
            else add(1,x);
        }
    }
    system("pause");
    return 0;
}