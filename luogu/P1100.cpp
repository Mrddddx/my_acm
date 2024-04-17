#include<bits/stdc++.h>
using namespace std;
string s="00000000000000000000000000000000";
string s1="0";
int p=0;
int a[10086];
void ten2a(long long x,int n)
{
    int t=0;
    long long N=1;
    char c;
    while(N<=x) N*=n;
    N/=n;

    while(N!=0)
    {
        a[++t]=x/N;
        x-=a[t]*N;
        N/=n;
    }
    for(int i=1;i<=t;i++)
    {
        c='0'+a[i];
        s[31+i-t]=c;
        
    }
    /*for(int i=0;i<32;i++)
    cout<<s[i];
    cout<<endl;*/
}
long b2ten()//转十进制
{
    int len=s.size();
    long long  ten=0;
    for(int i=0;i<len;i++)
    {
            ten=ten*2+(s[i]-'0');

    }
    return ten;
}

int main()
{
    long long a;
    char ch;
    cin>>a;
    ten2a(a,2);
    for(int i=0;i<16;i++)
    {
        ch=s[i];s[i]=s[i+16];s[i+16]=ch;
    }
    /*for(int i=0;i<32;i++)
    cout<<s[i];
    cout<<endl;*/
    cout<<b2ten();
    system("pause");
    return 0;
}