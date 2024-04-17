#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
double a[N];
double tree[N << 2];
double tree2[N << 2]; //平方和
double tag[N << 2];
ll ls(ll p) {return p << 1;}
ll rs(ll p) {return p << 1|1;}
void push_up(ll p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];
    tree2[p] = tree2[ls(p)] + tree2[rs(p)];
}
void build(ll p, ll pl, ll pr)
{
    tag[p] = 0;
    if(pl == pr)
    {tree[p] = a[pl]; tree2[p] = a[pl] * a[pl]; return;}
    ll mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}
void addtag(ll p, ll pl, ll pr, double d)
{
    tag[p] += d;
    tree2[p] +=  2 * d * tree[p] + (pr - pl + 1) * d * d ;
    tree[p] += d * (pr - pl + 1);
    
} 
void push_down(ll p, ll pl, ll pr)
{
  if(tag[p]){
    ll mid = (pl + pr) >> 1;
    addtag(ls(p), pl, mid, tag[p]);
    addtag(rs(p), mid + 1, pr, tag[p]);
    tag[p] = 0;
  }
}
void update(ll L, ll R, ll p, ll pl, ll pr, double d)
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
double query(ll L, ll R, ll p, ll pl , ll pr){
  if(pl >= L && R >= pr) return tree[p];
  push_down(p, pl, pr);
  double res = 0;
  ll mid = (pl + pr) >> 1;
  if(L <= mid) res += query(L, R, ls(p), pl, mid);
  if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
  return res;
}
double query2(ll L, ll R, ll p, ll pl , ll pr){
  if(pl >= L && R >= pr) return tree2[p];
  push_down(p, pl, pr);
  double res = 0;
  ll mid = (pl + pr) >> 1;
  if(L <= mid) res += query2(L, R, ls(p), pl, mid);
  if(R > mid) res += query2(L, R, rs(p), mid + 1, pr);
  return res;
}
int main()
{
  ll n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  while(m--){
    ll q, L, R;
    double d;
    cin >> q;
    if(q == 1){
      cin >> L >> R >> d;
      update(L, R, 1, 1, n, d);
    }
    else if(q == 2){
      cin >> L >> R;
      double ans = query(L, R, 1, 1, n) / (R - L + 1) ;
      cout << fixed << setprecision(4) << ans << endl;
    }
    else
    {
        cin >> L >> R;
        double sum = query(L, R, 1, 1, n);
        double ava = sum /(R - L + 1);
        double ans = (query2(L, R, 1, 1, n) - 2 * ava * sum)/ (R - L + 1) + ava * ava;
        cout << fixed << setprecision(4) << ans << endl;
        
    } 
  }
  //system("pause");
  return 0;
}