#include<bits/stdc++.h>
using namespace std;
const int N = 10100;
int f[N];
int v[N], w[N];
int n, W;
int all; //海深度
int main()
{
    cin >> all >> n >> W;

    for (int i = 1; i <= n; i ++)
        cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++)
        for(int j = W; j >= w[i]; j--)
            f[j] = max (f[j], f[j - w[i]] + v[i]);
            
    if(f[W] < all ) cout << "Impossible";
        else 
        for(int i = 0; i <= W; i++)
            if(f[i] >= all)
            {    
                cout << W - i;
                break;
            }
    system("pause");
    return 0;
}