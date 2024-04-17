#include<iostream>
#include<cstdlib>
using namespace std;
bool isComp[100000005];  //是不是素数
int main ()
{
	int n,ans=0;
	cin>>n;
	isComp[1]=1;  //1的特判
	for(int i=2;i*i<=n;i++) 
	{ 
	    if(isComp[i]==0)  //如果是素数
	        for(int j=i*i;j<=n;j+=i) //将他的倍数记为合数
	        	isComp[j]=1;   //标记
	}
	for(int i=1;i<=n;i++)
	{
		if(isComp[i]==0)  //如果是素数
			ans++;
    
    }
	cout<<ans<<endl; //输出
	system("pause");
    return 0;  //华丽结束
}