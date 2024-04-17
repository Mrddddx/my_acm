#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    int n,q;
    int i,j,k,b;
    cin>>n>>q;
    vector<vector<int>>a(n+1);
    for(int ii=1;ii<=q;ii++)
    {
        cin>>b>>i>>j;
        if(b==1)
        {
            cin>>k;
            if(a[i].size()<j+1)
            a[i].resize(j+1);
            a[i][j]=k;
        }
        else
        {
            cout<<a[i][j]<<endl;
        }
    }
    system("pause");
    return 0;
}