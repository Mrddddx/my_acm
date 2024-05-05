#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;

typedef pair<int,int> PII;
int n,unhappy[400005];
int happy[400005];
PII a[400005],tmp[400005];
int pre[400005];
void merge_count(int l,int r)
{
    if(l==r)return ;
    
    int mid=l+r>>1;
    merge_count(l,mid);
    merge_count(mid+1,r);
    
    int i=l,j=mid+1,idx=0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])//pair类型比较大小，默认比较first的大小
        {
            unhappy[a[i].y]+=j-mid-1;//加上后面比a[i].x更小的数
            tmp[idx++]=a[i++];
        }
        else
        {
            happy[a[j].y]+=mid-i+1;//加上前面比a[j].x更大的数
            tmp[idx++]=a[j++];
        }
    }
    
    while(i<=mid)
    {
        unhappy[a[i].y]+=j-mid-1;//加上后面比a[i].x更小的数
        tmp[idx++]=a[i++];
    }
    while(j<=r)tmp[idx++]=a[j++];
    for(int i=0;i<idx;i++)a[l+i]=tmp[i];
}

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i].x,a[i].y=i; pre[i] = a[i].x;}
    int A = 0, B = 0;
    merge_count(1,n);
    
    int res=0;
    for(int i=1;i<n;i++){
        B += pre[i] * (n - i - unhappy[i]);
    }

    for(int i=2;i<=n;i++){
        A += pre[i] * (i - happy[i] - 1);
    }
    cout << A - B;
    system("pause");
    return 0;
}