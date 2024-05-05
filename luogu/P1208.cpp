#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int ans;
struct st{
    int v, num;
} a[10086];
bool cmp(st x, st y){
    return x.v < y.v;
}
signed main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].v >> a[i].num;
    }
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        if(m > a[i].num){
            ans += a[i].v * a[i].num;
            m -= a[i].num;
        }
        else {
            ans += m * a[i].v;
            break;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}