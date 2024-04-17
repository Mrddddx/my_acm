#include<bits/stdc++.h>
using namespace std;
int n;
int a[100861];
int main()
{
  long long ans=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  for(int i=2;i<=n;i++)
    if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
  cout<<ans+a[1];
  system("pause");
  return 0;
}
    