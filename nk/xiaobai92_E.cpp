#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define maxheap(x) priority_queue<x,vector<x>,less<x> > 
#define minheap(x) priority_queue<x,vector<x>,greater<x> > 
#define endl '\n'
#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

int n,m,v[1000005],w[1000005],f[1000005],ff[1000005];
int now[1000005];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

    //f[i][j]：前i个中选，体积>=j的最小价值
    int res=1e18;
    memset(f,0x3f,sizeof f);
    memset(ff,0x3f,sizeof ff);
    f[0]=0;
    for(int i=1;i<=n;i++)
        for(int j = m;j >= 0 ;j++)
        {
            f[j]=min(f[j],f[max((int)0, j - v[i])]+w[i]);
            ff[j] = min(ff[j], ff[max((int)0, j - v[i])] + w[i]);
            ff[j] = min(ff[j], f[max((int)0, j -2 * v[i])] + w[i] / 2);
        }
    int ans = min(f[m], ff[m]);
    cout<< ans <<endl;
    //cout<<res<<endl;

    system("pause");
    return 0;
}