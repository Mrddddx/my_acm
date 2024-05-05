#include<bits\stdc++>
#define int long long
using namespace std;

int n,h[400005],tree[400005],unhappy[400005];
int happy[400005];
int lowbit(int x)
{
    return x&-x;
}

void add(int a,int b)
{
    for(int i=a;i<=400005;i+=lowbit(i))tree[i]+=b;
}

int ask(int x)
{
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i))res+=tree[i];
    return res;
}
long long ans, A, B;
int pre[400005];
signed main()
{


    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        pre[i] = h[i];
        h[i]++;   
    }
    for(int i=1;i<=n;i++)
    {
        happy[i]+=ask(400005)-ask(h[i]);
        add(h[i],1);
    }
    
    memset(tree,0,sizeof tree);//初始化
    for(int i=n;i>=1;i--)
    {
        unhappy[i]+=ask(h[i]-1);
        add(h[i],1);
    }
    
    int res=0;
    for(int i=1;i<n;i++)
    {
        B += pre[i] * (n - i - unhappy[i]);
        //cout << B << ' ';
    }
    //cout <<  '\n';
    for(int i = 2;i <= n;i++)
    {
        A += pre[i] * (i - happy[i] - 1);
        //cout << A << ' ';
    }
    cout << A - B;
    system("pause");
    return 0;
}