#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 30;
int A[N];
int cnt;
int a, b;
int n, m;
int main()
{
    cin >> n >> m;
    cin >> a >> b;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(x > a + b) continue;
        A[++cnt] = y;
    }
    int ans = 0;
    sort(A + 1, A + 1 + cnt);
    for(int i = 1; i <= cnt; i++){
        if(m < A[i]) break;
        ans++;
        m -= A[i];
    }
    cout << ans;
    system("pause");
    return 0;
}