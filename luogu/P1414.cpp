#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int fac[N], cnt;
int n;
int gcd(int x, int y){
    return !(x % y) ? y : gcd(y, x % y);
}
signed main(){
    cin >> n;
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxn = max(a[i], maxn);
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j) continue;
            fac[j]++;
            if(j != a[i] / j) fac[a[i] / j]++;
        }
    }
    int k = maxn;
    for(int i = 1; i <=n; i++){
        while(fac[k] < i) k--;
        cout << k << endl;
    }
    system("pause");
    return 0;
}