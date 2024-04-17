#include<iostream>
#include<cstdlib>
using namespace std;
long long qzd(int x,int m,long long y)
{
    long long n=0;
    while(1)
    {
       if(n%x==m) return n;
        n=n+y;
    }
}
int main()
{
    long long n,m;
    long long a[101],b[101];
    long long sum=1;
    long long c;
    long long ans=0;
    long long zd;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum*=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        c=sum/a[i];
        zd=qzd(a[i],b[i],c);
        ans=(ans+zd)%sum;
    }
    cout<<ans;
    system("pause");
    return 0;
}