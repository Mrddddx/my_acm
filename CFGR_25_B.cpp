#include <bits/stdc++.h>
using namespace std;
int n, k;
int higher[200200]; //比本牛高的牛的位置
int t, pret;//t代表比本牛高的牛的数量,pret是上一把的
int cows[200200];
int pre;//k前面有pre个比它高的
int dist;//每两个higher之间的水平距离
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int maxn = 0;
        t = 0;
        higher[++t] = 0;//最开使的墙
        cin >> n;
        cin >> k;
        for(int i = 1; i <= n; i++)
            cin >> cows[i];
        for(int i = 1; i <= n; i++)
           if(cows[i] > cows[k]) higher[++t] = i;//自己也算所以>=
           else if(i == k) pre = t;
        if(t == 1)
        {
            cout << n - 1 << endl;
            continue;
        }// k最高
        if(pre == 1) //前面没有更高的
        {
            maxn = higher[2] - 2;//放在最前面,到更高的就停
            cout << maxn << endl;
            continue;
        }
        // 前面有更高的
        if(pre == 2) //只有一个更高的
        if(higher[2] == 1) //高的在最前边,就和它交换
        {
            maxn = k - higher[2] - 1;
            cout << maxn << endl;
            continue;
        }
        else //如果不是
        {
            maxn = max(higher[2] - 2,k - higher[2] ); //换在最前面 ， 和高的交换
            cout << maxn << endl;
            continue;
        }
        if(higher[2] == 1)
        {
            maxn = higher[3] - higher[2] - 1;
            
            cout << maxn << endl;
        }
        else 
        {
            maxn = max(higher[2] - 2,higher[3] - higher[2]);
            cout << maxn << endl;
        }
    } 

    system("pause");
    return 0;
}