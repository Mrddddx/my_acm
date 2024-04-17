#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
long long ans;
int main()
{
    int n;
    cin >> n;
    int x, y;
    while(n--)
    {
        cin >> x;
        q.push(x);
    }
    while(q.size() > 1)
    {
        x = q.top(), q.pop();
        y = q.top(), q.pop();
        x += y;
        ans += x;
        q.push(x);
    }
    cout << ans;
    system("pause");
    return 0;
}