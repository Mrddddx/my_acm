#include<bits/stdc++.h>
using namespace std;
int ans;
int n, m;
int R[100], B[100], W[100];
int compute(int x, int y){
    int r, w, b;
    w = x * m - W[x];
    b = (y - x) * m - (B[y] - B[x]);
    r = (n - y) * m - (R[n] - R[y]);
   //cout << w << b << r << '\n';
    return w + b + r;
}
int main(){
    cin >> n >> m;
    int r = 0, w = 0, b = 0;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){
            char ch;
            cin >> ch;
            if(ch == 'R') r++;
            if(ch == 'W') w++;
            if(ch == 'B') b++;
        }
        R[i] = r, B[i] = b, W[i] = w;  
    }
    //cout << R[n] << B[n] << W[n] << '\n';
    int maxn = n * m;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j < n; j++)
            maxn = min(maxn, compute(i, j));
    }

    cout << maxn;
    system("pause");
    return 0;

}