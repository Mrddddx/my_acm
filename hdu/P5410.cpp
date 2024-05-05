#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e7 + 10;
ll  ans, cnt;
string b;
ll zz[N];
ll exkmp(string s){
    int n = s.size();
    s = "#" + s;
    ll  L = 1, R = 0;
    ans = n + 1;
    zz[1] = n;
    for(ll  i = 2; i <= n; i++){
        //cout << i << ' ' << L << ' ' << R << '\n'; 
        if(i > R) zz[i] = 0;
        else zz[i] = min(zz[i - L + 1], R - i + 1);
        while(i + zz[i] <= n && s[zz[i] + 1] == s[i + zz[i]]) zz[i] ++;
        if(i + zz[i] - 1 > R) L = i, R = i + zz[i] - 1;
        ans ^=1ll * i *(zz[i] + 1);
        //cout << i << ' ' << L << ' ' << R << z[i] << '\n'; 
    
        //cout << '\n';
    }
    return ans;
}
ll exkmp2(string s){
    int n = s.size();
    s = "#" + s;
    vector<ll> z(n + 1);
    ll  L = 1, R = 0;
    ans = 0;
    for(ll i = 1; i <= n; i++){
        //cout << i << ' ' << L << ' ' << R << '\n'; 
        if(i > R) z[i] = 0;
        else z[i] = min(zz[i - L + 1], R - i + 1);
        while(i + z[i] <= n && cnt > z[i] && b[z[i] + 1] == s[i + z[i]]) z[i] ++;
        if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1;
        ans ^= 1ll * (i *(z[i] + 1));
        //cout << i << ' ' << L << ' ' << R << z[i] << '\n'; 
    
        //cout << '\n';
    }
    return ans;
}
int main(){
    string a;
    cin >> a >> b;
    cnt = b.size();
    cout << exkmp(b) << '\n';
    b = "#" + b;
    cout <<exkmp2(a);
    system("pause");
    return 0;
}