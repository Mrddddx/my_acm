#include <bits/stdc++.h>
using namespace std;
long long sum[200200];//前缀和

int n;
int a[202020];
int b[200200]; //标记有1
int ans[202020];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {

    int ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
        if (sum [i] == 0) b[i + 1] = 1;
    }
    cin >> a[n];
    sum[n] = sum [n - 1] ^ a[n];
    if (sum[n] == 0) 
    {
        int i = n;
        while (b[i] == 1) b[i] = 0, i--;
        b[i] = 1;
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
        if(b[i] == 1) 
        {
            flag = 1;
            b[i] = 0;
            cout << 1;
        }
        else if (flag == 1) cout << 0;
    if (flag == 0) cout << 0;    
    cout <<endl;
    //break;
    }
    system("pause");
    return 0;
}