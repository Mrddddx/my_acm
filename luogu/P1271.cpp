#include<iostream>
#include<cstdlib>
#define MAXS 1010
using namespace std;
int num[MAXS];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        num[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        while(num[i]--)
        cout<<i<<' ';
    }
    system("pause");
    return 0;
}