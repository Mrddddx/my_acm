#include <bits/stdc++.h> 
using namespace std;
int T, M, S;
int flag = 0;
int f[301010];
int main()
{
    cin >> M >> S >> T;
    for(int i = 1; i <= T; i++)
    {
        if(M >= 10)
            f[i] = f[i - 1] + 60, M -= 10;
        else
            f[i] = f[i - 1], M += 4; 
    }
    for(int i=1 ; i <= T; i++)
    {
        f[i] = max(f[i], f[i-1] + 17);
        if (f[i] >= S) 
        {
            cout<<"Yes"<<endl<<i;
            flag = 1;
            break;
        }
    }
    if (flag == 0) cout<<"No"<<endl<<f[T];
    system("pause");
    return 0;
}