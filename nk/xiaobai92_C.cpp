#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
struct st{
   int v, num; 
} a[N];
long long ans;
bool cmp(st x, st y){
    return x.v < y.v;
}
long long maxn;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].v; a[i].num = 1;
    }
    cin >> k;
    int t = 1;
    sort(a + 1, a + 1 + n, cmp);
    int pre = -1;
    while(a[n].v >= k && a[n].v != pre){
        ans = 0;
        pre = a[n].v;
        for(int i = t; i <= n; i++){
            if(a[i].v == k) t = i, ans += a[i].num;
            a[i].num <<= 1;
            a[i].v = ceil(a[i].v / 3.0);
            
        }
        maxn = max(maxn, ans);
        //cout << ans << ' ';
    }
    cout << maxn;
    system("pause");
    return 0;
}