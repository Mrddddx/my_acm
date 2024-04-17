#include <bits/stdc++.h>
using namespace std;
int ans;
int L ,R;
int main()
{
    cin >> L >> R;
    for(int i = L; i <= R; i++)
    {
        if(i%2 == 1 || i % 4 == 0) ans ++; 
    }
    cout << ans;
    system("pause");
    return 0;
}   