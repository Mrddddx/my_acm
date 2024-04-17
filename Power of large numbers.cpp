#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int MOD = 1000000007;
int n;
string A,B;

long long a;
long long c;//作为一个补充因子
void A2a()
{
    a=0;//每次都要初始化
    for(int i=0;i<A.length();i++)
    {
        a=(a*10+A[i]-'0')%MOD;
    }
}
void divideB()
{
    int i;
    c=1;//初始化
    i=B.length();
    int k=0;
    do
    {  
        for(int j=k;j<i-1;j++)
            {
                B[j+1]+=(B[j]-'0')%2*10;
                B[j]='0'+(B[j]-'0')/2;
            }
        if((B[i-1]-'0')%2==1) c=(c*a)%MOD;
        B[i-1]='0'+(B[i-1]-'0')/2;
        if(i>k+1||(B[k]>'1'&&i==k+1)) {a=(a*a)%MOD;}
        if(B[k]=='0') {k++;}
    }while(!(i==k));
    a=(a*c)%MOD;
    c=0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A;
        cin>>B;
        A2a();
        divideB();
        cout<<a<<endl;
    }
    system("pause");
    return 0;
}
//第一次剪枝：每个B，只求一次B的长度
//第二次剪枝：去掉earse操作