#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls (p << 1)
#define rs (p << 1 | 1)
const int N = 5e5 + 5;
int n, m;
ll tree[N << 2];
ll se[N << 2], ma[N << 2];
int num[N << 2];
ll tag[N << 2];
ll B[N << 2];
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    } 
    //cout << x *f << endl;
    return x * f;
}
void pushup(int p)
{
    tree[p] = tree[ls] + tree[rs];
    ma[p] = max(ma[ls], ma[rs]);

    if(ma[ls] == ma[rs])
    {
        num[p] = num[ls] + num[rs];
        se[p] = max(se[ls], se[rs]);
    }
    else {
        se[p] = max(se[ls], se[rs]);
        se[p] = max(se[p], min(ma[ls], ma[rs]));
        num[p] = ma[ls] > ma[rs] ? num[ls] : num[rs];
    }
}
void pushB(int p)
{
    B[p] = max(B[ls], B[rs]);
}
void build(int p, int pl, int pr)
{
    tag[p] = 0;
    if(pl == pr) {
        tree[p] = read();
        B[p] = ma[p] = tree[p];
        num[p] = 1;
        se[p] = -1;
        return;
    }
    int mid = pr + pl >> 1;
    build(ls, pl, mid);
    build(rs, mid + 1, pr);
    pushup(p);
    pushB(p);
}  
void add(int p, int pl, int pr,int x)
{
    cout << "addtag: " << x << endl;
    tag[p] += x;
    tree[p] += x * (pr - pl + 1);
    ma[p] += x;
    if(ma[p] > B[p]) B[p] = ma[p];
    if(se[p] != -1) se[p] += x;
}
void minn(int p, int x)
{
    if(x >= ma[p]) return;
    cout << "mintag: " << x << endl; 
    tree[p] -= num[p] * (ma[p] - x);
    ma[p] = x;
}
void pushdown(int p, int pl, int pr)
{
    int mid = pr + pl >> 1;
    if(tag[p])
    {
        add(ls, pl, mid, tag[p]);
        add(rs, mid + 1, pr, tag[p]);
        tag[p] = 0;
    }    
}
void pushdown2(int p, int pl, int pr)
{
    minn(ls, ma[p]);
    minn(rs, ma[p]);
}
void Add(int L, int R, int p, int pl, int pr, int x)
{
    if(pl <= L && R >= pr){
        add(p, pl, pr, x);
        return;
    }
    pushdown(p, pl, pr);
    int mid = pl + pr >> 1;
    if(L <= mid) Add(L, R, ls, pl, mid, x);
    if(R > mid) Add(L, R, rs, mid + 1, pr, x);
    pushup(p);
}
void Min(int L, int R, int p, int pl, int pr, int x)
{
    if(x >= ma[p]) return;

    if(pl <= L && R >= pr && x > se[p])
    {
        minn(p, x);
        return;
    }
    pushdown(p, pl, pr);
    int mid = pr + pl >> 1;
    if(L <= mid) Min(L, R, ls, pl, mid, x);
    if(R > mid) Min(L, R, rs, mid + 1, pr, x);
    pushup(p);
}
ll query(int L, int R, int p, int pl, int pr)
{
    ll ans = 0;
    if(L <= pl && R >= pr) return tree[p];
    pushdown(p, pl, pr);
    int mid = pr + pl >> 1;
    if(L <= mid) ans += query(L, R, ls, pl, mid);
    if(R > mid) ans += query(L, R, rs, mid + 1, pr);
    return ans;
}
ll queryM(int L, int R, int p, int pl ,int pr)
{
    ll ans = 0;
    if(L <= pl && R >= pr) return ma[p];
    pushdown(p, pl, pr);
    int mid = pr + pl >> 1;
    if(L <= mid) ans = max(ans, queryM(L, R, ls, pl, mid));
    if(R > mid) ans = max(ans, queryM(L, R, rs, mid + 1, pr));
    return ans;
}
ll queryB(int L, int R, int p, int pl, int pr)
{
    ll ans = 0;
    if(L <= pl && R >= pr) return B[p];
    pushdown(p, pl, pr);
    int mid = pr + pl >> 1;
    if(L <= mid) ans = max(ans, queryB(L, R, ls, pl, mid));
    else ans = max(ans, queryB(L, R, rs, mid + 1, pr));
    return ans;
}
int main()
{
    cin >> n >> m;
    int x, op, L, R;
    build(1, 1, n);
    while(m--)
    {
        cin >> op >> L >> R;
        if(op == 1) {
            cin >> x;
            Add(L, R, 1, 1, n, x);
        }
        if(op == 2){
            cin >> x;
            Min(L, R, 1, 1, n, x);
        }
        if(op == 3)
            cout << query(L, R, 1, 1, n) << endl;
        if(op == 4)
            cout << queryM(L, R, 1, 1, n) << endl;
        if(op == 5)
            cout << queryB(L, R, 1, 1, n) << endl;
    }
    system("pause");
    return 0;
}