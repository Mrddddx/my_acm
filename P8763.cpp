#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
int n;

ll two2ten(string s) //转十进制
{
    ll ans = 0;
    int sz = s.size();
    for(int i = 1; i <= sz; i++)
    {
        if(s[sz - i] == 'O') 
            ans += (ll) 1 << i - 1; 
    }
    return ans;
}
int sz;
string ten2two(ll x) //转十进制
{
    string s;
    int k = 0;
    while(k < n)
    {
        if((x >> k) & 1) 
            s[k] = '1';
        else s[k] ='0'; 
        k++;
    }
    return s;

}
ll ans ;
int main()
{
    string s;
    cin >> n >> t;
    cin >> s;
    ans = two2ten(s);

    while(t--)
    {
        ans ^= (ans >> 1);
    }
    cout << ans;
    s = ten2two(ans);
    for(int i = 0; i < n; i++)
        cout << s[i];
    system("pause");
    return 0;
}