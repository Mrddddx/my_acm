#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int blk[N]; //对空位置的标记
int rep[N];
int a[N], t[N];
long long ans;
int n;
int main()
{
    cin >> n;
    for(int i; i <= n; i++)
        {
            cin >> t[i];
            if(t[i] < i) 
            {
                cout << "-1" ;
                return 0;
            }
        }
    for(int i; i <= n; i++)
        cin >> a[i]; 

    system("pause");
    return 0;
}