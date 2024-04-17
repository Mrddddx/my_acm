#include <bits/stdc++.h> 
using namespace std;
int N, M;
int nums[1010], b[1010];
int f[41][41][41][41];
int jump[10];
int maxn;
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> nums[i];
    for (int i = 1; i <= M; i++)
    {
        cin >> b[i];
        jump[b[i]]++;
    }
    f[0][0][0][0] = nums[1];
    for(int a = 0;a <= jump[1]; a++)
        for(int b = 0;b <= jump[2]; b++)
            for(int c = 0;c <= jump[3]; c++)
                for(int d = 0;d <= jump[4]; d++)
                {
                    int to = a*1 + b*2 + c*3 + d*4 + 1;
                    if(a) f[a][b][c][d] = max(f[a][b][c][d] , f[a-1][b][c][d] + nums[to]);
                    if(b) f[a][b][c][d] = max(f[a][b][c][d] , f[a][b-1][c][d] + nums[to]);
                    if(c) f[a][b][c][d] = max(f[a][b][c][d] , f[a][b][c-1][d] + nums[to]);
                    if(d) f[a][b][c][d] = max(f[a][b][c][d] , f[a][b][c][d-1] + nums[to]);
                    if (f[a][b][c][d] > maxn ) maxn = f[a][b][c][d];
                    //cout << a << b << c << d <<endl;
                }
    cout<<maxn;

    system("pause");
    return 0;
}