#include <bits/stdc++.h> 
using namespace std;
int dp[2010][2010];
int main()
{ 
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=0;i<=m;i++) dp[0][i]=i;
    
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
      if(s1[i]==s2[j]) dp[i+1][j+1]=dp[i][j];
      else dp[i+1][j+1]=min(min(dp[i][j+1],dp[i+1][j]),dp[i][j])+1;
    }
    cout<<dp[n][m]<<endl;
    system("pause");
    return 0;
}