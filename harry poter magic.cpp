#include<iostream>
#include<cstring>
using namespace std;
int a[11][101],b[10];

    int j;
void fill(int x,int y,int z)
{
    if(y==0) return;
    if(x/y>=1)
    {a[z][++b[z]]=j;x=x-y;}
    fill(x,y/2,z+1); 
}
int main()
{
    for(int i=1;i<=31;i++)
    {
        j=i;
        fill(i,16,1);
    }
    for(int i=1;i<=5;i++)
    {
        int t=0;
        for(int k=1;k<=b[i];k++)
        {cout<<a[i][k]<<' ';
            t++;
            if(t%8==0) cout<<endl;
        }
        cout<<endl<<endl;
    }
    system("pause");
    return 0;
}