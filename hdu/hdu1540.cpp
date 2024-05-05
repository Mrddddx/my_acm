#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int ls(int p) {return p << 1;}
int rs(int p) {return p << 1 | 1;}
int tree[N << 2], pre[N << 2], suf[N << 2];
int history[N];
void push_up(int p, int len)
{
    pre[p] = pre[ls(p)];
    suf[p] = suf[rs(p)];
    if(pre[ls(p)] == (len - (len >> 1))) pre[p] = pre[ls(p)] + pre[rs(p)];
    if(suf[rs(p)] == (len >> 1)) suf[p] = suf[ls(p)] + suf[rs(p)];
}
void build(int p, int pl, int pr)
{
    if(pl == pr) {tree[p] = pre[p] = suf[p] = 1; return;}
    int mid = pr + pl >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p, pr - pl + 1);
}
void update(int x, int c, int p, int pl, int pr)
{
    if(pl == pr) {tree[p] = suf[p] = pre[p] = c; return;}
    int mid = pr + pl >> 1;
    if(x <= mid) update(x, c, ls(p), pl, mid);
    else update(x, c, rs(p), mid + 1, pr);
    push_up(p, pr - pl + 1);
}
int query(int x, int p, int pl, int pr)
{
    if(pl == pr) return tree[p];
    int mid = (pl + pr) >> 1;
    if(x <= mid){
        if(x + suf[ls(p)] > mid) return suf[ls(p)] + pre[rs(p)];
        else return query(x, ls(p), pl, mid);
    }
    else {
        if(mid + pre[rs(p)] >= x) return suf[ls(p)] + pre[rs(p)];
        else return query(x, rs(p), mid + 1, pr);
    }
}
int main()
{
    int n , m, x, tot;
    char op;
    while(cin >> n >> m )
    {build(1, 1, n);
    tot = 0;
    while(m --)
    {
        cin >> op;
        if(op == 'Q')
        {
            cin >> x;
            cout << query(x, 1, 1, n) << endl;
        }
        else if(op == 'D') 
        {
            cin >> x;
             history[++tot] = x;
            update(x, 0, 1, 1, n);
        }
        else 
        {
            x= history[tot--];
            update(x, 1, 1, 1, n);
        }
    }
    }system("pause");
    return 0;
}