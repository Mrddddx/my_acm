#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll a[N];
ll tree[N << 2];
ll tag[N << 2];
ll ls(ll p) {return p << 1;}
ll rs(ll p) {return p << 1|1;}
void push_up(ll p)
{
  tree[p] = tree[ls(p)] + tree[rs(p)];
}
void build(ll p, ll pl, ll pr)
{
  tag[p] = 0;
  if(pl == pr){tree[p] = a[pl]; return;}
  ll mid = (pl + pr) >> 1;
  build(ls(p), pl, mid);
  build(rs(p), mid + 1, pr);
  push_up(p);
}
void addtag(ll p, ll pl, ll pr)
{
  tag[p] = !tag[p];
  tree[p] = pr - pl + 1 - tree[p];
} 
void push_down(ll p, ll pl, ll pr)
{
  if(tag[p]){
    ll mid = (pl + pr) >> 1;
    addtag(ls(p), pl, mid);
    addtag(rs(p), mid + 1, pr);
    tag[p] = 0;
  }
}
void update(ll L, ll R, ll p, ll pl, ll pr)
{
  if(L <= pl && pr <= R){
    addtag(p, pl, pr);
    return;
  }
  push_down(p, pl, pr);
  ll mid = (pl + pr) >> 1;
  if(L <= mid) update(L, R, ls(p), pl, mid);
  if(R > mid) update(L, R, rs(p), mid + 1, pr);
  push_up(p);
}
ll query(ll L, ll R, ll p, ll pl , ll pr){
  if(pl >= L && R >= pr) return tree[p];
  push_down(p, pl, pr);
  ll res = 0;
  ll mid = (pl + pr) >> 1;
  if(L <= mid) res += query(L, R, ls(p), pl, mid);
  if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
  return res;
}

int main()
{
    /*ifstream fin;
    ofstream fout;
    fin.open("P3870.txt");
    fout.open("P3870_out2.txt");*/

    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    a[i] = 0;
    build(1, 1, n);
    while(m--){
    ll q, L, R; 
    cin >> q;
    if(q == 0){
        cin >> L >> R ;
        update(L, R, 1, 1, n);
    }
        else {
        cin >> L >> R;
        cout << query(L, R, 1, 1, n) << endl;
    }
  }
  system("pause");
  return 0;
}