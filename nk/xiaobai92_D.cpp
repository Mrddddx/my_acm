#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,a[100005];

signed main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)cin>>a[i];

    int sum=0,sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        sum1+=i*a[i];
        sum2+=i*i*a[i];
    }

    int res=1e18;
    for(int i=1;i<=n;i++)
        res=min(res,i*i*sum-2*i*sum1+sum2);
    cout<<res<<endl;

    system("pause");
    return 0;
}