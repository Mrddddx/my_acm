#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int mod=10007;
int n;
string s;
int ans;
vector<string> haxi[mod+2];
void insert()
{
    int hash=1;
    for(int i=0;s[i];i++)
    {
        hash=(hash*128+s[i])%mod; 
    }
    for(int i=0;i<haxi[hash].size();i++)
    if(haxi[hash][i]==s) return;
    haxi[hash].push_back(s);
    ans++;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        insert();
    }
    cout<<ans;
    system("pause");
    return 0;
}
