#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int len = unique(a + 1, a + 1 + n) - a - 1;
    int k = 0;
    for(int i = 1; i <= len - 1; i++){
        if(a[i] - a[i - 1] > 1) {k = i; break;}
    }
    //cout << k << '\n';
    if(k & 1 || (k == 0 && len & 1)) cout << "Alice\n";
    else cout << "Bob\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}