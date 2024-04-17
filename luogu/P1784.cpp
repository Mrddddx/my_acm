#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdlib>
using namespace std;
int n;
int a[10][10];
int l[10][10],h[10][10],w[50][20];
void print()
{
    for(int i=1;i<=9;i++)
    {for(int j=1;j<=9;j++)
    {   
        cout<<a[i][j]<<" ";
    }cout<<endl;}
}
void fill(int i,int j)
{
    
    //if(i==9)    print();
    if(i>9) 
    {
        print();
        system("pause");
        exit(0);
    }
    if(j>9) fill(i+1,1);  
    if(a[i][j]==0)
        for(int x=1;x<=9;x++)
    {
        if(w[(i-1)/3*10+(j-1)/3][x]==0&&l[j][x]==0&&h[i][x]==0&&a[i][j]==0)
        {
            a[i][j]=x;
            w[(i-1)/3*10+(j-1)/3][x]=l[j][x]=h[i][x]=x;
            fill(i,j+1);
            w[(i-1)/3*10+(j-1)/3][x]=l[j][x]=h[i][x]=0;
            a[i][j]=0;
        }
    }
    else fill(i,j+1);
}
int main()
{
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
    {   
        cin>>a[i][j];
        int x=a[i][j];
        w[(i-1)/3*10+(j-1)/3][x]=l[j][x]=h[i][x]=x;
       // cout<<(i-1)/3*10+(j-1)/3<<" ";
    }
    fill(1,1);
    system("pause");
    return 0;
}