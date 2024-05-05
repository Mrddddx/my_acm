#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int ans;
int a[10086];
int f[10086];
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        //if(f[m - v[j]]) ans++;
        for(int j = m; j >= a[i]; j--){
            f[j] += f[j - a[i]];
        }
    }
    cout << f[m];
    system("pause");
    return 0;
}