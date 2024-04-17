#include <bits/stdc++.h>
using namespace std;
string s;
int bef,aft;
int a[101];
int b2ten()//转十进制
{
    int len=s.size();
    int ten=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            ten=ten*bef+(s[i]-'0');
        else 
            ten=ten*bef+(s[i]-'A'+10);
    }
    return ten;
}

void ten2a(int x,int n)//由十进制转
{

    int t=0;
    long long N=1;
    char c;
    while(N<=x) {N*=n;}
    N/=n;
    
    while(N!=0)
    {
        a[++t]=x/N;
        x-=a[t]*N;
        N/=n;
    }
    for(int i=1;i<=t;i++)
    {
        //cout<<a[i]<<' ';
        if(a[i]<=9)
            c='0'+a[i];
        else 
            c=('A'+a[i]-10);
        cout<<c;
    }

}
int main()
{

    cin>>bef;
    cin>>s;
    cin>>aft;
    int ten=b2ten();
    //cout<<ten;
    ten2a(ten,aft);
    
    system("pause");
    return 0;
}