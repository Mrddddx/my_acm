#include<bits/stdc++.h>
using namespace std;
#define ls (p << 1)
#define rs (p << 1 | 1)
const int N = 1e5 + 5;
int n, m, k;
int tree[N << 3], tag[N << 3];
int a[N];
struct Sgement{
    int l, r;
} s[N];
int area[N], cnt, len; //离散后的区间 
void push_up(int p){
    tree[p] = tree[ls] + tree[rs];
}

void addtag(int p, int pl, int pr, int d){
    tag[p]++;
    tree[p] += pr - pl + 1;
}
void push_back(int p, int pl, int pr){
    if(tag[p]){
        int mid = pl + pr >> 1;
        addtag(ls, pl, mid, tag[p]);
        addtag(rs, mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}
void update(int L ,int R, int p, int pl, int pr){
    if(L <= pl && R >= pr){
        addtag(p, pl, pr, 1);
        return;
    }
    push_back(p, pl, pr);
    int mid = pl + pr >> 1;
    if(L <= mid) update(L, R, ls, pl, mid);
    if(R > mid) update(L, R, rs, mid + 1, pr);
    push_up(p);
}
int query(int x, int p, int pl, int pr){
    if(pl == x && pr == x)  return tree[p];
    int mid = pr + pl >> 1;
    if(x <= mid) return query(x, ls, pl, mid);
    return query(x, rs, mid + 1, pr);
}
int q[N << 1]; //最后的区间
int pre[N << 1];
int back[N << 1];
long long ans;
int main()
{
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i].l >> s[i].r;
        area[++cnt] = s[i].l;
        area[++cnt] = s[i].r;
    }
    sort(area + 1, area + cnt + 1);
    len = unique(area + 1, area + 1 + cnt) - area - 1;
    for(int i = 1; i <= n; i++)
    {
        int L, R;
        L = lower_bound(area + 1, area + len + 1, s[i].l) - area;
        R = lower_bound(area + 1, area + len + 1, s[i].r) - area;
        update(L, R, 1, 1, len);
    }
    for(int i = 1; i <= len; i++){
        q[i] = query(i, 1, 1, len);
        pre[i] = pre[i - 1] + q[i];
    //    cout << q[i] << ' ';
    }
    for(int i = len; i >= 1; i--){
        back[i] = back[i + 1] + q[i];
    }
    int i = 1, j = 1; //尺取法
    while(j <= len){
        while(pre[j] - pre[i - 1] < k && j < n) j++;
        while(pre[j] - pre[j] - pre[i] >= k && i < j) i++;
        //if(pre[j] - pre[i - 1] < k ) break;
        i++,j++;
        ans += (area[i]) * (m - area[j] + 1);  
    }
    cout << ans;
    system("pause");
    return 0;
}