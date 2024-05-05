
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k;
 
int a[N];
void solve()
{
    cin >> n >> k;
    if(n == 1) {cout << k << endl; return;}
    int j = 0;
        for(int i = 1; i < n - 1; i++)
            cout << 0 << ' ';
    while(k >= (1 << j)) j++;
    j--;
    int m = (1 << j) - 1;
    cout << m << ' ';
    int R = k - m;
    cout << R;
    cout << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    system("pause");
}