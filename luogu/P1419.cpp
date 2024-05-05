#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int S, T;
double a[N];
bool check(int x){
    
}
signed main(){
    cin >> n >> S >> T;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int L = S, R = T;

    while(L < R){
        int mid = L + R >> 1;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    system("pause");
    return 0;
}