#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 30;
int a[N];
int main()
{
    int n, k;
    ll ans = 0; 
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++){
        if(a[i] + a[i - 1] >= k){
            int eat = a[i - 1] + a[i] - k;
            a[i] = max(0, a[i] - eat);
            ans += eat;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}