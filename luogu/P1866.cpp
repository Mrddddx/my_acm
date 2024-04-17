#include<bits/stdc++.h>
using namespace std;
const int N=1000000007;
long long ans;
int a[10101];
int main()
{
    int n;
    ans=1;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int m;
        m=a[i];
        ans=(ans*(m-i+1))%N;
    }
    cout<<ans;
    system("pause");
    return 0;
}