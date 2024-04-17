#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[300300];
int Xor[300300];//前
int main()
{

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= q; i ++)
    {
        int x, p;
        cin >> x >> p;
        a[x] = p;
    }
    

    system("pause");
    return 0;
}