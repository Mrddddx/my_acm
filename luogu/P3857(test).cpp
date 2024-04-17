#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll a[100];
bool zero; //有异或为0的组合
int n, m;
ll two2ten(string s) //转十进制
{
    ll ans = 0;
    int sz = s.size();
    for(int i = 1; i <= sz; i++)
    {
        if(s[sz - i] == 'O') 
            ans += 1 << i - 1; 
    }
    return ans;
}

void Guess() // 高斯消元
{
    int i, k = 1;
    ll j = (ll) 1 << 62;
    for(; j; j >>= 1)
    {
        for(i = k; i <= n; i++)
            if(a[i] & j) break;
        if(i > n) continue; //没有第j位为1的a[]
        swap(a[i], a[k]);
        for(i = 1; i <= n; i++)
            if(i != k && a[i]&j) a[i] ^= a[k];
        k++;
    }
    k--;
    if(k != n) zero = true;
    else zero = false;
    n = k;
}


int main()
{
    n = 50;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(i == j) cout << 'O';
            else cout <<'X';
        cout << endl;
    }
    //cout << ans;
    system("pause");
    return 0; 
}