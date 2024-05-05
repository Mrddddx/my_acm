#include<bits/stdc++.h>
using namespace std;
int a[100000001];
int prime[20008611], cnt;
void pre(){
    a[1] = 1;
    for(int i = 2; i <= 100000000; i++){
        if(!a[i])
            prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <=100000000; j++){
            a[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    pre();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        cout << prime[x] << '\n';
    }
    
    system("pause");
    return 0;
}