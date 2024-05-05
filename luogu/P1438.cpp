#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
#define ls (p << 1)
#define rs (p << 1 | 1)
ll tree[N << 2];
struct st
{
    ll d;
    ll k;
}  tag[N << 2];
ll n, m;
void pushup(int p)
{
    tree[p] = tree[ls] + tree[rs];
}
void build(int p , int pl, int pr)
{
    tag[p].d = tag[p].k = 0;
    if(pl == pr) {cin >> tree[p]; return;}
    int mid = pl + pr >> 1;
    build(ls, pl, mid);
    build(rs, mid + 1, pr);
    pushup(p);
}
void addtag(int p, int pl, int pr, int K, int D)
{
    tag[p].k = K;
    tag[p].d = D; 
    tree[p] =tree[p] + ((K + K + D * (pr - pl)) * (pr - pl + 1) >> 1);
}
void pushdown(int p, int pl, int pr)
{
    if(tag[p].k || tag[p].d)
    {
        ll mid = pr + pl >> 1;
        addtag(ls, pl, mid, tag[p].k, tag[p].d);
        addtag(rs, mid + 1, pr, tag[p].k + tag[p].d * (mid + 1 - pl), tag[p].d);
        tag[p].d = tag[p].k = 0;
    }

}
void update(int L, int R, int p, int pl, int pr, int K, int D)
{
    if(L <= pl && R >= pr) {
        addtag(p, pl, pr, K + D * (pl - L), D);
        return ;
    }
    pushdown(p, pl, pr);
    int mid = pr + pl >> 1;
    if(L <= mid) update(L, R, ls, pl, mid, K, D);
    if(R > mid) update(L , R, rs, mid + 1, pr, K , D);
    pushup(p);
}
ll query(int t, int p, int pl, int pr)
{
    if(t == pl && t == pr) return tree[p];
    pushdown(p, pl, pr);
    int mid = pl + pr >> 1;
    if(t <= mid) return query(t, ls, pl, mid);
    if(t > mid) return query(t, rs, mid + 1, pr);
    return 0; 
}
int main()
{
    cin >> n >> m;
    int op, L, R,  K, D;
    build(1, 1, n);
    while(m--)
    {
        int k = 0;
        for(int i =  1; i <= n << 2; i++)
        {
            cout << tree[i] << ' ';
            if((i + 1) % (1 << k) == 0) k++, cout << endl;
        }
        cin >> op;
        if(op == 1)
        {
            cin >> L >> R >> K >> D;
            update(L, R, 1, 1, n, K, D);
        }
        else 
        {
            cin >> L;
            cout << query(L, 1, 1, n) << endl;
        }
    }
    system("pause");
    return 0;
}