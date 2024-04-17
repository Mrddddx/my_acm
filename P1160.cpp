#include<iostream>
#include<cstdlib>
using namespace std;
struct st
{
    int pre,nxt,key;
    st(int _key=0,int _pre=0,int _nxt=0)
    {
        key=_key;pre=_pre;nxt=_nxt;
    }
};
st s[100861];
int tot;
int index[100861];//索引
void ins_back(int x,int y)
{
    int now=index[x];
    s[++tot]=st(y,now,s[now].nxt);
    s[s[now].nxt].pre=tot;
    s[now].nxt=tot;
    index[y]=tot;
}
void ins_front(int x,int y)
{
    int now=index[x];
    s[++tot]=st(y,s[now].pre,now);
    s[s[now].pre].nxt=tot;
    s[now].pre=tot;
    index[y]=tot;
}

void del(int x)//删除
{
    int now=index[x];
    s[s[now].pre].nxt=s[now].nxt;
    s[s[now].nxt].pre=s[now].pre;
    index[x]=0;
}
int main()
{
    int n,m;
    int k,p;
    cin>>n;
    s[0]=st();
    ins_back(0,1);
    for(int i=2;i<=n;i++)
    {
        cin>>k>>p;
        if(p) ins_back(k,i);
        else ins_front(k,i);
    }
    cin>>m;
    int x;
    for(int i=1;i<=m;i++)
    {    
        cin>>x;
        if(index[x]!=0) del(x);
    }
    int now=s[0].nxt;//0必定是链头
    while(now)//now!=0表示没有回到链头
    {
        cout<<s[now].key<<' ';
        now=s[now].nxt;
    }
    system("pause");
    return 0;
}