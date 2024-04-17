# include <iostream>
# include <stdlib.h>
using namespace std;
int N,M,C;
int l,r;
long long a[1011][1011];
long long suml[1011][1011];
long long sum[1011][1011];
long long maxn=0;
int mx,my;
int main()
{
    //输入数据
    cin>>N>>M>>C;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            cin>>a[i][j];
        }
    
    //降维度,将C排合成一个
    for(int i=1;i<=N;i++)
    {    for(int j=1;j<=C;j++)
        {
            suml[i][1]+=a[i][j];
        }
        for(int j=C+1;j<=M;j++)
        {
            suml[i][j-C+1]=suml[i][j-C]+a[i][j]-a[i][j-C];
        }
    }
        for(int i=1;i<=N;i++)
        for(int j=1;j<=M-C+1;j++)
        {
            //cout<<suml[i][j]<<' ';
            if(sum[i][j]>maxn) 
            {
                maxn=sum[i][j];
                mx=i;my=j;
            }
        }
    //降维度,再将合成后的数据列组合，降成0维
    //cout<<endl;
    for(int j=1;j<=M-C+1;j++)
    {    
        for(int i=1;i<=C;i++)
        {
            sum[1][j]+=suml[i][j];
        }
        for(int i=C+1;i<=M;i++)
        {
            sum[i-C+1][j]=sum[i-C][j]+suml[i][j]-suml[i-C][j];
        }
    }
    for(int i=1;i<=N-C+1;i++)
        for(int j=1;j<=M-C+1;j++)
        {
            //cout<<sum[i][j]<<' ';
            if(sum[i][j]>maxn) 
            {
                maxn=sum[i][j];
                mx=i;my=j;
            }
        }
    cout<<mx<<' '<<my;
    system("pause");
    return 0;
}  
