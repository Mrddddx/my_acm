#include<iostream>
#include<cstdlib>
using namespace std;
int N[20023];//第n个有三个以上prime factor的数
int b[100000]={0};//是否是质数,有多少个质因子
void preproc()
{
    for(int i=2;i<=9999;i++)
    {
        if(b[i]==0)
        {
            for(int j=2*i;j<=9999;j+=i)
            {
                b[j]++;
            }
        }
    }
}
int main()
{
    int T;

    int n;
    preproc();
    int num=1;//记录第num个ans
    for(int i=1;i<=9999;i++)
    {
        if(b[i]>=3) {N[num++]=i;}
    }
    cin>>T;  
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        cout<<N[n]<<endl;
    }
    system("pause");
    return 0;
}