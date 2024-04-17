#include<bits/stdc++.h>
using namespace std;
long long p;
long long q;
long long mul;
int ans;
long long  gcd(long  x,long long y)
{
   long long R;
   R=y%x;
   while(R!=0)
   {
      y=x;
      x=R;
      R=y%x;
   }
   return x;
}
int main()
{
  long long a,b,c,d;
  cin>>a>>b>>c;
  d=a*b/gcd(a,b);
  d=c*d/gcd(c,d);
  cout<<d;
  system("pause");
  return 0;
}