#include <bits/stdc++.h>
using namespace std;
int n,m;
long long s;
struct st
{
    int w,v;
} a[202020];
int r[202020],l[202020];
long long sum[202020];
int sumb[202020];
long long  mxa,mia;
void f(int x)//求那些石头满足条件,并求前缀和
{
    memset(sum,0,sizeof(sum));
    memset(sumb,0,sizeof(sumb));
    for(int i=1;i<=n;i++)
    {
        sumb[i]=sumb[i-1];
        sum[i]=sum[i-1];
        if(x<=a[i].w)
        {
            sumb[i]++;
            sum[i]+=a[i].v;
        }
        //cout<<sum[i]<<' '<<sumb[i]<<endl;
    }
}
long long d()//求y
{
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=(sum[r[i]]-sum[l[i]-1])*(sumb[r[i]]-sumb[l[i]-1]);
    }

    return ans;
}
int main()
{
    cin>>n>>m>>s;
    int mx=0,mi=0xfffffff;
    long long minn=0,ans;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i].w>>a[i].v;
        if(mx<a[i].w) mx=a[i].w;
        if(mi>a[i].w) mi=a[i].w;
    }
    for(int i=1;i<=m;i++)
        cin>>l[i]>>r[i];
    f(mi);mia=d();
    f(mx);mxa=d();
    minn=0xffffffffffff;

    int mid;
    while(mi<=mx)
    {
        mid=(mi+mx)>>1;
        f(mid);
        ans=d();
        if(ans>s) 
        {
            mi=mid+1;
        }
        else 
        {
            
            mx=mid-1;
             
        }
        long long da=abs(ans-s);
        if(da<minn) minn=da;  

    }
    cout<<minn;
    system("pause");
    return 0;
}