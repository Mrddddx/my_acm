#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
ll ans;
ll a[N], b[N];
void read(ll &x)
{
    char c = 0;
    ll f = 1; x = 0;
    c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while( c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    } 
    x *= f;
}
int main()
{
    memset(a, 1, sizeof a);//懒得盘界
    int n;
    cin >> n;
    int x, y;
    for(int i = 1; i <= n; i++)
    {
        read(a[i]);
        b[a[i]] ++;
    }
    int t = 0;
    for(int i = 1; i <= 100000; i++)
        while(b[i]--)
            a[++t] = i;

    memset(b, 1, sizeof b);//再次利用
    int j = 1, k = 0, i = 1;
    while(++k < n)
    {
        ll m, w, sum;
        if(a[i] < b[j])
            m = a[i], i++;
        else 
            m = b[j], j++;
        if(a[i] < b[j])
            w = a[i], i++;
        else  w = b[j], j++;
        sum = m + w;
        b[k] = sum;
        ans += sum;
    }
    cout << ans;
    system("pause");
    return 0;
}