#include<bits/stdc++.h>
using namespace std;
int w[10100],v[10010];
long long f[10000010];
int main()
{
  int n,m;
  cin>>m>>n;
  for(int i=1;i<=n;i++)
     cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
      for(int j=0;j<=m;j++)
        if(j>=w[i])     
          f[j]=max(f[j],f[j-w[i]]+v[i]);
  cout<<f[m]<<endl;
  system("pause");
  return 0;
}