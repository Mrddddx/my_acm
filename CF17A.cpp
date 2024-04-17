#include<iostream>
#include<cstdlib>
using namespace std;
int N[1023];//第n个good prime
int b[2086]={0};//是否是质数,有多少个质因子
int c[2086]={0};//是否是好质数(好素数=好+素数)
void preproc(int n)
{
    int pre;
    int now;
    for(int i=2;i<=n;i++)
    {
        if(b[i]==0)
        {
            c[i]++;//素数
            for(int j=2*i;j<=n;j+=i)
            {
                b[j]++;
            }
        if(i!=2)
        {
            now=i;
            c[now+pre+1]++;//好
            pre=i;
        }
        else pre=2;
    
        }
    }
}
int main()
{
    int T;

    int n;
    int k;
    cin>>n>>k;
    preproc(n);
    int num=1;//记录第num个ans
    for(int i=1;i<=n;i++)
    {
        if(c[i]==2) {N[num++]=i;}
    }
    if(num>k) cout<<"YES";
    else cout<<"NO";
    system("pause");
    return 0;
}