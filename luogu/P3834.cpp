#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int cnt;
int a[N], b[N], root[N];
struct st
{
    int L, R, sum;
} tree[N << 5];
int update(int pre, int pl, int pr, int x){
    int p = ++ cnt;
    tree[p].L = tree[pre].L;
    tree[p].R = tree[pre].R;
    tree[p].sum = tree[pre].sum + 1;
    int mid = pr + pl >> 1;
    if(pl < pr)
    {
        if(x <= mid)
            tree[p].L = update(tree[pre].L, pl, mid, x);
        else 
            tree[p].R = update(tree[pre].R, mid + 1, pr, x);
    } 
    return p;
}
int query(int u, int v, int pl, int pr, int k)
{
    if(pl == pr) return pl;
    int x = tree[tree[v].L].sum - tree[tree[u].L].sum;
    int mid = pl + pr >> 1;
    if(x >= k) 
        return query(tree[u].L, tree[v].L, pl, mid, k);
    else 
        return query(tree[u].R, tree[v].R, mid + 1, pr, k - x);
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> b[i], a[i] = b[i];
    sort(b + 1, b + 1 + n);
    int size = unique(b + 1, b + 1 + n) - b - 1;
    for(int i = 1; i <= n; i++)
    {
        int x = lower_bound(b + 1, b + 1 + size, a[i]) - b; //离散化后ai的对应值
        root[i] = update(root[i - 1], 1, size, x);
    }
    int L, R, k;
    while(m--)
    {
        cin >> L >> R >> k;
        int t = query(root[L - 1], root[R], 1, size, k);
        cout << b[t] << endl;
    }
    system("pause");
    return 0;
}
