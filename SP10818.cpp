#include<iostream>
#include<cstdlib>
using namespace std;
int b[10086111]={0};//是否是质数,如果不是表示最小质因子
void preproc(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(b[i]==0||b[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(b[j]==0)
                b[j]=i;
            }
        }
    }
}
int main()
{
    int T;

    int n;
    int maxn=0;
    while(cin>>n)
    {
        if(n>maxn)
        {
            maxn=n;
            preproc(maxn);
        }
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        cout<<"1 x ";
        while(b[n]!=n)
        {
            cout<<b[n]<<" x ";
            n=n/b[n];
        }
        cout<<b[n]<<endl;
    }
    system("pause");
    return 0;
}