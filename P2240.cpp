#include<bits/stdc++.h>
using namespace std;
int N,T;
struct st
{
    double v;
    int m;
} a[110];

double ans;

bool cmp(st x,st y)
{
    return (x.v>y.v);
}
int main()
{
  cin>>N>>T;
  int M,V;
  for(int i=1;i<=N;i++)
  {
    cin>>M>>V;
    a[i].v=V/(M*1.0);
    //cout<<'n'<<a[i].v<<' ';
    a[i].m=M;   
  }
  sort(a+1,a+1+N,cmp);
  //for(int i=1;i<=N;i++) cout<<'n'<<a[i].v<<' '; 
  for(int i=1;i<=N;i++)
  {
    if(T==0) break;
    if(T>=a[i].m) 
    {
        ans+=a[i].m*a[i].v;
        T-=a[i].m;
    }
    else
    {
        ans+=T*a[i].v;
        T=0;
    }
  }
  printf("%.2lf",ans);
  system("pause");
  return 0;
}
    