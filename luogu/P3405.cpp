#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int mod=1000007;
int n;
string a,b;
int ans;
vector<pair<int,int>> haxi[mod+2];
void insert(int x)
{
    for(int i=0;i<haxi[x].size();i++)
    {
        if(x==haxi[x][i].first) 
        {
            haxi[x][i].second++;
            break;
        }
    }
    haxi[x].push_back(pair<int,int>(x,1));
}
int gethash(string x,string y)
{
    //cout<<((x[0]-'A')+(x[1]-'A')*26+(y[0]-'A')*26*26+(y[1]-'A')*26*26*26)<<endl;
    return ((x[0]-'A')+(x[1]-'A')*26+(y[0]-'A')*26*26+(y[1]-'A')*26*26*26);
}
int find(int x)
{
    for(int i=0;i<haxi[x].size();i++)
    {
        if(x==haxi[x][i].first) 
        return haxi[x][i].second;
    }
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a[0]!=b[0]||a[1]!=b[1])
        ans+=find(gethash(b,a));
        insert(gethash(a,b));
    }
    cout<<ans;
    system("pause");
    return 0;
}
