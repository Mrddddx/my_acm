#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
int main()
{
    queue<int>q;
    int n,m;
    int p=0;//计数器
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        q.push(i);
    while(!q.empty())
    {
        p++;
        if(p==m)
        {
            p=1;
            cout<<q.front()<<' ';
            q.pop();
        }
        q.push(q.front());
        q.pop();
    }
    system("pause");
    return 0;
}