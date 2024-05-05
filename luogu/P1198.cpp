#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll m, n;
ll MOD;
ll tree[N << 2];

int ls(int p) {return p << 1;} 
int rs(int p) {return p << 1 | 1;}

void push_up(int p)
{ tree[p] = max(tree[ls(p)] , tree[rs(p)]);}

void update(int t, int p, int pl, int pr, int x)
{
    if(t == pl && t == pr) tree[p] = x;
    else 
    {
        int mid = pr + pl >> 1;
        if(t <= mid) update(t, ls(p), pl, mid, x);
        if(t > mid) update(t, rs(p), mid + 1, pr, x);
        push_up(p);
    }
}
ll query(int L, int R, int p, int pl, int pr)
{
    if(L <= pl && R >= pr) return tree[p];
    ll ans = 0;
    int mid = pr + pl >> 1;
    if(L <= mid) ans = max(ans, query(L, R, ls(p), pl, mid));
    if(R > mid) ans = max(ans ,query(L, R, rs(p), mid + 1, pr));
    return ans;
}
int main()
{
    char op;
    ll x;
    ll last = 0;
    cin >> m >> MOD;
    for(int i = 1; i <= m; i++)
    {
        cin >> op;
        if(op == 'Q') 
        {
            cin >> x; 
            last = query(n - x + 1, n, 1, 1, m); 
            cout << last << endl;
        }
        if(op == 'A') 
        {
            cin >> x; 
            update(n + 1, 1, 1, m, (x + last) % MOD); 
            n++;
        }
    } 
    system("pause");
    return 0;
}