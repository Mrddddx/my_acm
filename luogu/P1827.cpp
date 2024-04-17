#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int n;
string pre,in;
void build(int x,int y,int p,int q)
{
    for(int i=p;i<=q;i++)
    {
        if(pre[x]==in[i])
        {
            build(x+1,x+i-p,p,i-1);
            build(x+1-p+i,y,i+1,q);
            cout<<pre[x];
            return; 
        }
    }
}
int main()
{
    cin>>in>>pre;
    int l=pre.length()-1;
    build(0,l,0,l);
    system("pause");
    return 0;
}