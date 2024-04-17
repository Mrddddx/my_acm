#include<iostream>
#include<cstdlib>
#include<map>
#include<string>
using namespace std;

int n;
int m;
map<int ,int> a;

int main()
{
    cin>>n;
    int num;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        a[num]=i;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>num;
        cout<<a[num]<<endl;
    }
    system("pause");
    return 0;
}