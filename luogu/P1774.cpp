#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x&(-x))
const int N = 5e5+5;
int tree[N], Rank[N], n;
struct point
{
    int num;
    int val;
} a[N];

void updata(int x,int d)
{
    while(x <= N)
    {
        tree[x] += d;
        x += lowbit(x);
    }
}
long long Sum(int x)
{
    long long ans = 0;
    while(x > 0)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

bool cmp(point x, point y)
{
    if (x.val == y.val) return x.num < y.num;
    else return x.val < y.val;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].num = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        Rank[a[i].num] = i; //离散化
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        updata(Rank[i], 1);
        ans += i - Sum(Rank[i]);
    }
    cout << ans ;
    system("pause");
    return 0;
}

