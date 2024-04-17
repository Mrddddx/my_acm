#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll mod;
ll a[N];
ll tree[N << 2];
ll tag[N << 2];
ll tag2[N << 2] = {1};
ll ls(ll p) {return p << 1;}
ll rs(ll p) {return p << 1|1;}
void push_up(ll p)
{
  tree[p] = (tree[ls(p)] + tree[rs(p)]);
}
void build(ll p, ll pl, ll pr)
{
  tag[p] = 0;
  tag2[p] = 1;
  if(pl == pr){tree[p] = a[pl]; return;}
  ll mid = (pl + pr) >> 1;
  build(ls(p), pl, mid);
  build(rs(p), mid + 1, pr);
  push_up(p);
}
void addtag(ll p, ll pl, ll pr, ll d)
{
  tag[p] += d;
  tree[p] += d * (pr - pl + 1);
} 
void addtag2(ll p, ll pl, ll pr, ll d)
{
  tag2[p] =(tag2[p] * d) % mod;
  tag[p] = (tag[p] * d) % mod;
  tree[p] =(tree[p] * d) % mod;
} 
void push_down(ll p, ll pl, ll pr)
{
  
  if(tag2[p] != 1){
    ll mid = (pl + pr) >> 1;
    addtag2(ls(p), pl, mid, tag2[p]);
    addtag2(rs(p), mid + 1, pr, tag2[p]);
    tag2[p] = 1;
  }
  if(tag[p]){
    ll mid = (pl + pr) >> 1;
    addtag(ls(p), pl, mid, tag[p]);
    addtag(rs(p), mid + 1, pr, tag[p]);
    tag[p] = 0;
  }
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
{
  if(L <= pl && pr <= R){
    addtag(p, pl, pr, d);
    return;
  }
  push_down(p, pl, pr);
  ll mid = (pl + pr) >> 1;
  if(L <= mid) update(L, R, ls(p), pl, mid, d);
  if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
  push_up(p);
}

void update2(ll L, ll R, ll p, ll pl, ll pr, ll d)
{
  if(L <= pl && pr <= R){
    addtag2(p, pl, pr, d);
    return;
  }
  push_down(p, pl, pr);
  ll mid = (pl + pr) >> 1;
  if(L <= mid) update2(L, R, ls(p), pl, mid, d);
  if(R > mid) update2(L, R, rs(p), mid + 1, pr, d);
  push_up(p);
}
ll query(ll L, ll R, ll p, ll pl , ll pr){
  if(pl >= L && R >= pr) return tree[p] % mod;
  push_down(p, pl, pr);
  ll res = 0;
  ll mid = (pl + pr) >> 1;
  if(L <= mid) res = (res + query(L, R, ls(p), pl, mid)) % mod;
  if(R > mid) res = (res + query(L, R, rs(p), mid + 1, pr)) % mod;
  return res % mod;
}

int main()
{
  ll n, m;  

  cin >> n >> m >> mod;

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  while(m--){
    ll q, L, R, d; cin >> q;
    if(q == 2){
      cin >> L >> R >> d;
      update(L, R, 1, 1, n, d);
    }
    else if(q == 1){
      cin >> L >> R >> d;
      update2(L, R, 1, 1, n ,d);
    }
    else {
      cin >> L >> R;
      cout << query(L, R, 1, 1, n) << endl;
    }
  }
  system("pause");
  return 0;
}