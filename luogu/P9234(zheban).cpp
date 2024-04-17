//参考代码

#include<iostream>
#include<algorithm>
using namespace std;
int n, ans = 31;//劈瓜次数
long long int m, total;
long long int A[30];
long long int B[31];//后缀和，即当前瓜重量加上后面所有瓜重量（不使用会有时间超限问题）
int i;
void dfs(int i, long long int sum, int cnt)//dfs深搜，瓜编号i、已得瓜重sum、切瓜次数cnt
{
    if (sum == m)
    {
        ans = min(ans, cnt);
        return;
    }
    if (sum > m || i > n|| cnt >= ans||sum+B[i]<m)return;//总重超出或编号大于瓜数
    dfs(i + 1, sum + A[i], cnt);//买
    dfs(i + 1, sum, cnt);//不买
    dfs(i + 1, sum + A[i] / 2, cnt + 1);//切一半买
}
int main()
{
 
    cin >> n >> m;
    m *= 2;//防止小数出现
    for (i = 0;i < n;i++)
    {
        cin >> A[i];
        A[i] *= 2;
        total += A[i];//总重
    }
    sort(A, A + n, greater<long long int>());//从大到小排列瓜重
    for (i = n-1;i >=0;i--)
    {
        B[i] = A[i] + B[i + 1];
    }
    if (total < m)cout << -1;
    else
    {
        dfs(0, 0, 0);
        if (ans == 31)cout << -1;
        else cout << ans;
    }
    return 0;
}