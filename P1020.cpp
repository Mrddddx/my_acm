#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
int n = 0;//a[]的长度
int d[N];
int t = 0;//d[]的长度
int d2[N];
int t2 = 0;
int main()
{

    for(; cin >> a[++n];);
    n--;
    d[1] = a[1], t++;
    for(int i =  2; i <= n; i++)
    {
        if(a[i] <= d[t]) //有更小的
            d[++t] = a[i];
        else //交换d[]中第一个比它大的数 
        {
            int j = lower_bound(d + 1, d + 1 + t, a[i], greater<int>()) - d;
            d[j] = a[i];
        }
    }
    cout << t << endl;;
    d2[1] = a[1], t2++;
    for(int i =  2; i <= n; i++)
    {
        if(a[i] > d2[t2]) //有更大的
            d2[++t2] = a[i];
        else //交换d[]中第一个比它大的数 
        {
            int j = lower_bound(d2 + 1, d2 + 1 + t2, a[i]) - d2;
            d2[j] = a[i];
        }
    }
    cout << t2;
    system("pause");
    return 0;
}