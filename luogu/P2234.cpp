#include <bits/stdc++.h> 
using namespace std;

int ans;

struct Turnover{
    int day,v;
} a[35050];

bool cmp(Turnover x , Turnover y)
{
    return x.v < y.v;
}


int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        a[i].day = i;
    }
    sort(a + 1 , a + 1 + n , cmp);
    for (int i = 1; i <= n ;i++)
    {
        if(a[i].day == 1) 
        {
            ans += a[i].v;
            continue;
        }
        int mx = 0xfffffff;
        for (int j = i + 1; j <= n; j++) 
            if(a[i].day > a[j].day)
            {
                mx = min(a[j].v - a[i].v , mx);
                break;
            }
        for (int j = i - 1; j >= 1; j--)
            if(a[i].day > a[j].day)
            {
                mx = min(a[i].v - a[j].v , mx);
                break;
            }
        ans += mx;
    }
    cout << ans;
    system("pause");
    return 0;
}