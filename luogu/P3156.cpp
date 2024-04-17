#include<iostream>
#include<cstdlib>
using namespace std;
int a[2008611];
int main()
{
    int b;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b;
        cout<<a[b]<<endl;
    }
    system("pause");
    return 0;
}