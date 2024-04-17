#include <bits/stdc++.h>
using namespace std;

int ans;
int n;
int x;
int edge[1010][1010];
int du[1010]; //度
void dfs(int x)
{
    for(int i = 1; i <= 50; i++)
        if(edge[x][i])
        {
            edge[x][i]--;
            edge[i][x]--;
            dfs(i);
            cout << i << ' ' << x << endl;
        }
}
int main()
{
    int T;
    int cnt = 0;
    cin >> T;
    while (T--)
    {
    
    cnt ++;
    cout << "Case #" << cnt << endl;
    memset(edge , 0 , sizeof(edge));
    memset(du , 0 , sizeof(du));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v ;
        x = u;
        edge[u][v] ++;
        edge[v][u] ++;
        du[v] ++;
        du[u] ++;
    }
    int flag = 0;
    for (int i = 1; i <= 50; i++)
        if( du[i]&1 == 1 )
        {
            flag = 1;
            cout << "some beads may be lost\n";
            break;
        }
    
    if(!flag) dfs(x);

    }
    system("pause");
    return 0;
}