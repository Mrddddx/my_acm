#include<bits/stdc++.h>
using namespace std;
double a[105][105];
double eps = 1e-7;
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    
    for(int i = 1; i <= n; i++)
    {
        int maxn = i;
        for(int j = i + 1; j <=n; j++)
            if(fabs(a[j][i]) > fabs(a[maxn][i])) maxn = j;
        for(int j=1; j <= n + 1; j++)   swap(a[i][j], a[maxn][j]);
        if(fabs(a[i][i]) < eps)
        {
            cout << "No Solution";
            return 0;
        }

        for(int j = n + 1; j >= i; j--) a[i][j] = a[i][j]/a[i][i]; //这一行的主对角线元素变一

        for(int j = 1; j <= n; j++) // 消去其他主元
        if(j != i)
        {
            double temp = a[j][i] / a[i][i];
            for(int k = 1; k <= n + 1; k++) 
                a[j][k] -= a[i][k] * temp;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%.2f\n",a[i][n + 1]);
    system("pause");
    return 0;
}