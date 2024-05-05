#include<bits/stdc++.h>
using namespace std;
int a[1010], d[1010];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i - 1] = abs(a[i] - a[i - 1]);
    }
    int  f = 0;
    sort(d + 1, d + n);
    for(int i = 1; i < n; i++){
        //cout << d[i];
        if(i != d[i]) {f = 1; break;}
    }
    if(f) cout << "Not jolly";
    else cout << "Jolly";
    system("pause");
    return 0;
}