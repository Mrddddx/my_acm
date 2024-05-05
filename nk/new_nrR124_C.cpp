#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k;
int a[N];
struct Sgement{
    int l, r;
} s[N];
int area[N], cnt, len; //离散后的区间 

long long ans;
int D[N << 1];
int M[N << 1];
int num[N << 1], fnum[N << 1];
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
        fnum[lower_bound(area + 1, area + len + 1, s[i].l) - area] ++; 
        num[lower_bound(area + 1, area + len + 1, s[i].r) - area] ++;
        D[lower_bound(area + 1, area + len + 1, s[i].l) - area] = i;
        D[lower_bound(area + 1, area + len + 1, s[i].r) - area] = i;
    }
    int i = 1, j = 0; //尺取法
    int now = 0;
    int pj = 0;
    for(int i = 1; i <= len; i ++)
        cout << D[i];
        cout <<'\n';
    while(j < len){

        while(now < k && j < len){
            if(M[D[j]]) 
                now += num[++j];
            //cout << area[j] << ' ' << now << ' ';
            M[D[j]]++;
        }
        //cout << '\n';
        while(now >= k && i <= j)
        { 
            //cout << D[i];
            if(M[D[i]] >= 2)
                now -= fnum[i];
                //cout << area[i] << ' ' << now << ' ';
            i++;
        } 
        cout << '\n';
        //cout << area[i - 1] << ' ' << area[j] << '\n';
        ans += (area[i - 1] - pj) * (m - area[j] + 1);  
        pj = area[i - 1];
    }
    cout << ans;
    system("pause");
    return 0;
}