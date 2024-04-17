#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[120];
int main()
{
    memset(a,-1,sizeof(a));
    int n,m;
    cin>>m>>n;
    int t;
    int num=0,time=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        bool b=0;
        for(int i=1;i<=m;i++)
        {
            if(a[i]==t) {b=1;break;}
        }
        if(b) continue; 
        time++;
        a[++num]=t;
        if(num>m) 
        {
            num=1;
            a[num]=t;
        }
    }
    cout<<time;
    system("pause");
    return 0;
}