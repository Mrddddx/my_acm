#include <bits/stdc++.h> 
using namespace std;
int matrix[121][121];
int n;
int sum[121][121];
int maxn = -1* 0xfffffff;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            sum[i][j] =matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];  
        }
    for (int a = 1; a <= n; a++)
    for (int b = 1; b <= n; b++)
    for (int c = 1; c <= a; c++)
    for (int d = 1; d <= b; d++)
    {
        maxn = max(maxn , sum[a][b] - sum[a][d - 1] - sum[c - 1][b] + sum[c - 1][d - 1]);
    }
    cout << maxn;
    system("pause");
    return 0;
}