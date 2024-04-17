#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
struct st
{
    int left,right;
};
int ans;
int ma[20010],mi[20010];
void DGqsort(st a[],int l,int r)
{
    int m=(l+r)/2;
    st x=a[m];
    int i=l,j=r;
    do
    {
        while(a[i].left<x.left) i++;
        while(a[j].left>x.left) j--;
        if(i<=j)
        {
            st t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<r) DGqsort(a,i,r);
    if(j>l) DGqsort(a,l,j);
}
int main()
{
    st a[20020];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i].left>>a[i].right;
    DGqsort(a,1,n);
    int p=0;
    mi[++p]=a[1].left;ma[p]=a[1].right;
    for(int i=2;i<=n;i++)
    {
        if(a[i].left>ma[p]) 
        {
            ma[++p]=max(a[i].right,ma[p-1]);
            mi[p]=a[i].left;
        }
        else{
            ma[p]=max(ma[p],a[i].right);
        }
    }
    for(int i=1;i<=p;i++)
        //cout<<ma[i]<<' '<<mi[i];
        ans+=ma[i]-mi[i];
    cout<<ans;
    system("pause");
    return 0;
}