# include <iostream>
# include <stdlib.h>
using namespace std;
int n,p;
int x,y,z;
int a[5010101];
int d[5010101];
int d1,d2;
int after,ans=0x7fffffff;
int main()
{
    cin>>n>>p;
    a[0]=d[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=p;i++)
    {
        cin>>x>>y>>z;
        d[x]+=z;d[y+1]-=z;
    }
    after=a[0];
    for(int i=1;i<=n;i++)
    {
        after+=d[i];
        //cout<<after<<' ';
        if(after<ans) ans=after;
    }
    cout<<ans;
    system("pause");
    return 0;
}  
