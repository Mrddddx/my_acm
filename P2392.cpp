#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int a[101];
int f[10086];
int ans;
int main()
{
    int s[5];
    cin>>s[1]>>s[2]>>s[3]>>s[4];
    for(int ii=1;ii<=4;ii++)
    {
        int sum=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=s[ii];i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=1;i<=s[ii];i++)
        {
            for(int j=sum/2;j>=a[i];j--)
            f[j]=fmax(f[j],f[j-a[i]]+a[i]);
        }
        ans+=sum-f[sum/2];
    }
    cout<<ans;
    system("pause");
    return 0;
}