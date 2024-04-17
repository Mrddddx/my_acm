#include <bits/stdc++.h> 
using namespace std;
int ans = 100;
int n, m;
int a[101];
void count(int num , int x , int hav) //第num个瓜，x刀，已有hav重量的瓜
{
    
    if (hav == m) 
    {
        ans = min(ans , x); //找打一个答案，看刀数是否更小
        return ;
    }
    if (hav > m ) return ;//多了
    if (num == n + 1) return; //找完了

    count(num + 1 , x , hav + a[num]);//拿
    count(num + 1 , x + 1, hav + (a[num] >> 1)); //拿一半
    count(num + 1 , x , hav );//不拿
    
}
bool  cmp(int x , int y)
{
    return x > y;
}
int main()
{
    cin >> n >> m;
    m *= 2; //需要重量*2，每个瓜重量*2，这样就不用小数运算了
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a + 1 , a + 1 + n , cmp);
    count(1 , 0 , 0);
    if(ans != 100) cout << ans ;
    else cout << "-1";
    system("pause");
    return 0;
}