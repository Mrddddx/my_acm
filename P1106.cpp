#include<bits/stdc++.h>
using namespace std;
string s;
char maxn;
char maxi;
int main()
{
  int n;
  cin>>s;
  cin>>n;
  while(n-->0)
  {
    int b=0;
    int len=s.size();
    maxn=s[0];
    maxi=0;
    for(int i=1;i<len;i++)
    {
      if(maxn<s[i]) 
      {
        maxn=s[i];
        maxi=i;
      }
      if(s[i-1]>s[i]) {s.erase(i-1,1); break;}   
    }
    
    //cout<<s<<endl;
    if(len==s.size()) s.erase(maxi,1);
  }
  while(s[0]=='0'&&s.size()>1) s.erase(0,1);
  cout<<s;
  if(s.size()==0) cout<<0;
  system("pause");
  return 0;
}
    