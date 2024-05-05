#include<bits/stdc++.h>
using namespace std;
#define ls (p << 1)
#define rs (p << 1 | 1)
typedef long long ll;
const int N = 1e5 + 10;
int n, m, mod, r;
struct EDGE{
    int to, next;
} edge[N << 1];
int deep[N];
int son[N], fa[N], top[N], siz[N];
int id[N], w_new[N], num; //时间戳
int head[N << 1], cnt;
int w[N];
int tree[N << 2], tag[N << 2];
void init(){
    for(int i = 0; i < N << 1; i++)
        edge[i].next = head[i] = -1;
    cnt = 0;
}
void addedge(int u, int v){
    edge[cnt].to = v;    edge[cnt].next = head[u];   head[u] = cnt ++;
}

void dfs1(int x, int father){
    deep[x] = deep[father] + 1;
    fa[x] = father;
    siz[x] = 1;
    for(int i = head[x]; ~i; i = edge[i].next){
        int y = edge[i].to;
        if(y == father) continue;
        dfs1(y, x);
        siz[x] += siz[y];
        if(!son[x] || siz[son[x]] < siz[y])
            son[x] = y;
    }
}

void dfs2(int x, int topx){
    id[x] = ++num;
    w_new[num] = w[x]; 
    top[x] = topx;
    if(!son[x]) return;
    dfs2(son[x], topx);
    for(int i = head[x]; ~i; i = edge[i].next){
        int y = edge[i].to;
        if(y != fa[x] && y != son[x]) dfs2(y, y);
    }
}
void pushup(int p){
    tree[p] = tree[ls] + tree[rs];
    tree[p] %= mod;
}
void build(int p, int pl, int pr){
    tag[p] = 0;
    if(pl == pr) {
        tree[p] = w_new[pl];
        return;
    }
    int mid = pl + pr >> 1;
    build(ls, pl, mid);     build(rs, mid + 1, pr);
    pushup(p);
}
void addtag(int p, int pl, int pr, int k){
    tag[p] += k;
    tree[p] = (tree[p] + k * (pr - pl + 1)) % mod;
}
void pushdown(int p, int pl, int pr){
    if(tag[p]){
        int mid = pl + pr >> 1;
        addtag(ls, pl, mid, tag[p]);
        addtag(rs, mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}
void update(int L, int R, int p, int pl, int pr, int k){
    if(L <= pl && R >= pr) {
        addtag(p, pl, pr, k);
        return;
    }
    pushdown(p, pl, pr);
    int mid = pl + pr >> 1;
    if(L <= mid) update(L, R, ls, pl, mid, k);
    if(R > mid) update(L, R, rs, mid + 1, pr, k);
    pushup(p);
}

int query(int L, int R, int p, int pl, int pr){
    if(L <= pl && R >= pr){
        return tree[p] % mod;
    }
    pushdown(p, pl, pr);
    int ans = 0;
    int mid = pl + pr >> 1;
    if(L <= mid) ans += query(L, R, ls, pl, mid);
    if(R > mid) ans += query(L, R, rs, mid + 1, pr);
    return ans;
}
void range_update(int x, int y, int k){
    while(top[x] != top[y]){
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        update(id[top[x]], id[x], 1, 1, n, k);
        x = fa[top[x]];
    }
    if(deep[x] > deep[y]) swap(x, y);
    update(id[x], id[y], 1, 1, n, k);
}
int range_query(int x, int y){
    int ans = 0;
    while(top[x] != top[y]){
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        ans += query(id[top[x]], id[x], 1, 1, n);
        ans %= mod;
        x = fa[top[x]];
    }
    if(deep[x] > deep[y]) swap(x, y);
    ans += query(id[x], id[y], 1, 1, n);
    return ans % mod;
} 
void tree_update(int x, int k){
    update(id[x], id[x] + siz[x] - 1, 1, 1, n, k);
}
int tree_query(int x){
    return query(id[x], id[x] + siz[x] - 1, 1, 1, n) % mod;
}
int main()
{
    init();
    cin >> n >> m >> r >> mod;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i < n; i++){
        int u, v;    cin >> u >> v;
        addedge(u, v); addedge(v, u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    while(m--){
        int x, y, op, k;
        cin >> op;
        if(op == 1) {cin >> x >> y >> k;     range_update(x, y, k);}
        if(op == 2) {cin >> x >> y;     cout << range_query(x, y) << '\n';}
        if(op == 3) {cin >> x >> k;     tree_update(x, k);}
        if(op == 4) {cin >> x; cout << tree_query(x) << '\n';}
    }
    system("pause");
    return 0;
}