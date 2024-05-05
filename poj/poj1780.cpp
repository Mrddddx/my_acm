#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
const int N = 1e5;
int num[N];
stack<int> edg;
stack<char> ans;
int m;
void d(int x)
{
    int edge = 0;
    while(num[x] < 10)
    {
        edge = 10 * x + num[x];
        num[x]++;
        //cout << num[x] << endl;
        edg.push(edge);
        x = edge % m;
    }
}
int main()
{
    int n, edge;
    while(cin >> n && n != 0)
    {
        m = 1;
        for(int i = 1; i < n; i++)
            m *= 10;
        for(int i = 0; i < m; i++) num[i] = 0;
        d(0);
        while(edg.size())
        {
            edge = edg.top();
            edg.pop();
            ans.push(edge % 10 + '0');
            d(edge / 10);
        }
        for(int i = 1; i < n; i++)
            cout << 0;
        while(ans.size())
        {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    system("pause");
    return 0;
}