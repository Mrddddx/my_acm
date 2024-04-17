#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

string s[110];
string var;//变价

int up[110];//上升的
int down[110];//下降的
int ut;//上升的数量
int dt;//下降的数量
int all[110];//总排行榜

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >>s[i];
        cin >>var;
        if(var == "SAME") all[i] = i;
        else if(var == "UP") up[++ut] = i;
            else    down[++dt] = i;
    }
    int i = 0, j = 0;
    for(int k = 1; k <=n; k++)
    {
        if(all[k]) continue; //这个位置有人了
        if(i < dt) all[k] = down[++i];
        else all[k] = up[++j];
    }
    for(int k = 1; k <= n; k++)
        cout << s[all[k]] << endl;
    
    system("pause");
    return 0;
}