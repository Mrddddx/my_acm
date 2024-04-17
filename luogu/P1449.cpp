#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
int ans;
using namespace std;
int main()
{
    stack<int> s;
    char c;
    while(cin>>c)
    {
        if(c=='@') 
        {
            cout<<s.top();
            system("pause");
            return 0;
        }
        int a=0;//每个数字
        bool b=0;//是否是数字
        while(c<='9'&&c>='0')//如果是数字，得到它
        {
            a=a*10+c-'0';
            b=1;
            cin>>c;
        }
        if(b) s.push(a);//把数字放进栈
        int x,y;//两个数字
        if(c=='+')
        {
            x=s.top();
            s.pop();
            y=s.top();
            ans=y+x;
            s.pop();
            s.push(ans);
        }
        if(c=='-')
        {
            x=s.top();
            s.pop();
            y=s.top();
            ans=y-x;
            s.pop();
            s.push(ans);
        }
        if(c=='*')
        {
            x=s.top();
            s.pop();
            y=s.top();
            ans=y*x;
            s.pop();
            s.push(ans);
        }
        if(c=='/')
        {
            x=s.top();
            s.pop();
            y=s.top();
            ans=y/x;
            s.pop();
            s.push(ans);
        }
    }
    system("pause");
    return 0;
}