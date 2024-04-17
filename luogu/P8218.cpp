# include <iostream>
# include <stdlib.h>
using namespace std;
int n,m;
int l,r;
int a[100861],sum[100861];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    system("pause");
    return 0;
}  
