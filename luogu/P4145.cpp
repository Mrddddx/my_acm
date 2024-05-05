#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll tree[N << 2];
ll tag[N << 2];
ll ma[N << 2];
ll ls(ll p) {return p << 1;}
ll rs(ll p) {return p << 1|1;}
void push_up(ll p)
{
  tree[p] = tree[ls(p)] + tree[rs(p)];
  ma[p] = max(ma[ls(p)], ma[rs(p)]);
}
void build(ll p, ll pl, ll pr)
{
  tag[p] = 0;
  if(pl == pr){cin >> tree[p]; ma[p] = tree[p]; return;}
  ll mid = (pl + pr) >> 1;
  build(ls(p), pl, mid);
  build(rs(p), mid + 1, pr);
  push_up(p);
}

void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
{
  if(L <= pl && pr <= R && pr == pl){
    tree[p] = ma[p] = sqrt(ma[p]);
    return;
  }
  ll mid = (pl + pr) >> 1;
  if(L <= mid) update(L, R, ls(p), pl, mid, d);
  if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
  push_up(p);
}
ll query(ll L, ll R, ll p, ll pl , ll pr){
  if(pl >= L && R >= pr) return tree[p];
  ll res = 0;
  ll mid = (pl + pr) >> 1;
  if(L <= mid) res += query(L, R, ls(p), pl, mid);
  if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
  return res;
}

int main()
{
  ll n, m;
  cin >> n;
  build(1, 1, n);
  cin >> m;
  while(m--){
    ll q, L, R, d; cin >> q >> L >> R;
    if(L > R) swap(L , R);
    if(q == 0)
      update(L, R, 1, 1, n, 1);
    else 
      cout << query(L, R, 1, 1, n) << endl;
  }
  system("pause");
  return 0;
}