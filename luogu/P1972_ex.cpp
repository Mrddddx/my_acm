#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
struct node //离线记录
{
    int L,R,k;//k为查询的原始顺序
}q[N];
int pos[N];//第i个元素所在块
int cnt[N];//表示i出现次数
int a[N];
int ans[N];
bool cmp(node a,node b)
{
    if(pos[a.L]!=pos[b.L])
        return pos[a.L]<pos[b.L];
    if(pos[a.L] & 1) return a.R>b.R;
    return a.R<b.R;
}

int ANS=0;
void add(int x)
{
    cnt[a[x]]++;
    if(cnt[a[x]]==1 ) ANS++;
}

void del(int x)
{
    cnt[a[x]]--;
    if(cnt[a[x]]==0 ) ANS--;
}


int main()
{
    int n,m;
    cin>>n;
    int block=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[i]=(i-1)/block+1;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].L,&q[i].R);
        q[i].k=i;
    }
    sort(q+1,q+1+m,cmp);
    int L=1,R=0;
    for(int i=1;i<=m;i++)
    {
        while(L<q[i].L) del(L++);
        while(R>q[i].R) del(R--);
        while(L>q[i].L) add(--L);
        while(R<q[i].R) add(++R);
        ans[q[i].k]=ANS;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    system("pause");
    return 0;
}