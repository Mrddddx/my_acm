#include <bits/stdc++.h>
using namespace std;
const int N = 80112002;

int ans;
int n, m;
vector <int> edge[5010];
int rudu[5010]; //每个点是否有入边 1表示有
int cudu[5010]; //每个点是否有出边 1表示有
int b[5010]; //每个点是否入过队
queue <int> q;//用BFS拓扑排序
int energe[5010]; //可以理解为生物学的能力传递
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        rudu[v]++ ;
        cudu[u]++ ;
    }
    for (int i = 1; i <= n; i++)
    {
        if(rudu[i] == 0)
            energe[i] = 1, q.push(i); //入头 ,并带一个能量
    
    }
    while(!q.empty())
    {
        int now = q.front();
        cout << now << ' ';
        q.pop();
        if(cudu[now] == 0) //到底了
        {
            ans = (ans + energe[now]) % N ; //记录能量
            continue;
        }
        int sz = edge[now].size();
        for(int i = 0; i < sz; i++)
        {
            energe[edge[now][i]] = (energe[edge[now][i]] + energe[now]) % N; //传递能量
            rudu[edge[now][i]] --;
            if (rudu[edge[now][i]] == 0 ) q.push(edge[now][i]); //没有入度了，入队！
        }
    }
    cout << ans;
    system("pause");
    return 0;
}