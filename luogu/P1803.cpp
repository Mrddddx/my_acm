#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 30;
struct st{
    int x, y;
} a[N];
bool cmp(st x, st y){
    if(x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].y;
        cin >> a[i].x;
    }
    sort(a + 1, a + 1 + n, cmp);
    int ans = 1;
    int t = a[1].x;
    for(int i = 2; i <= n; i++)
    {
        if(a[i].y >= t) ans++, t = a[i].x;
    }
    cout << ans;
    system("pause");
    return 0;
}