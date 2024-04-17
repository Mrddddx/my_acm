#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

struct shits
{
    int t, l, h; //掉入时间，维持生命时间，高度
} a[110];
bool cmp(shits x, shits y)
{
    return x.t < y.t;
}
int f[3100]; 
int G = 10; //初始生命
int n, W;
int main()
{
    cin >> W >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].t >> a[i].l >> a[i].h;
    sort(a + 1, a + 1 + n, cmp);
    f[0] = 10;
    
    for(int i = 1; i <= n; i++)
        for(int j = W; j >=0; j--)
        if(f[j] >= a[i].t)
        {
            if(j + a[i].h >=W)
            {
                cout << a[i].t ;
                system("pause");
                return 0;
            }
            f[j + a[i].h] = max(f[j + a[i].h], f[j]);
            f[j] += a[i].l;
        }        
    cout << f[0] ; //第i时刻饿死
    system("pause");
    return 0;
}