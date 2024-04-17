#include <bits/stdc++.h>
using namespace std;
int dp[2][100086];
int s1[100086],s2[100086];
int main()
{ 
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s1[i];    
    for(int i=1;i<=n;i++)
        cin>>s2[i];
    int now=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(s1[i]==s2[j]) dp[now][j]=dp[!now][j-1]+1;
        else dp[now][j]=max(dp[!now][j],dp[now][j-1]);
      }
      now=!now;
    }
    cout<<dp[!now][n]<<endl;
    system("pause");
    return 0;
}