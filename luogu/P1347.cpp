#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;

vector <int> edge[30];
int cd[30], rd[30];//出度入度
int b[30];
int nums;//点的数量

int Re[30][30];//判断是否有重复边


int lsrd[30], lscd[30]; //临时出度入度

queue <int> q;
void init()//初始化
{
    nums = 0;
    for(int i = 1; i <= n; i++)
    lsrd[i] = rd[i], lscd[i] = cd[i];
    for(int i = 1; i <= n; i++)
        if(b[i]) nums++;
    while(!q.empty()) q.pop();
}
void findq()//找没有入度的点
{
    for(int i = 1; i <= n; i++)
        if(!rd[i] && b[i]) q.push(i);
}
bool bfs()
{
    int ans = 0;
    while(!q.empty())
    {
        ans ++;
        int x = q.front();
        q.pop();
        int sz = edge[x].size();
        for(int i = 0; i < sz; i++)
        {
            lsrd[edge[x][i]] --;
            if(lsrd[edge[x][i]] == 0) q.push(edge[x][i]);
        }
    }
    //cout << ans << nums;
    if (ans != nums) return false;
    else return true;
}
int main()
{
    int F2 = 0;//表示是否矛盾
    int F = 0;//表示是否不确定
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        
        cin >>  s;
        int u = s[0] - 'A' + 1, v = s[2] - 'A' + 1;
        b[u] = 1, b[v] = 1; //记录出现过的点
        if(!Re[u][v])
            Re[u][v] = 1, edge[u].push_back(v), cd[u] ++, rd[v] ++;

        init();
        findq();
        if(!bfs()) 
        {
            cout << "Inconsistency found after " << i << " relations.\n" ;
            system("pause");
            return 0;
        }
    }
    int flag = 0;
    for(int i = 1;  i <= n; i++)
        if(rd[i] && flag == 0) q.push(i), flag = 1;
        else if(rd[i] && flag == 0) 
        {F = 1; break;}
    
    if(!flag) F = 1;
    system("pause");
    return 0;
}