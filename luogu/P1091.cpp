#include <bits/stdc++.h> 
using namespace std;
int n;
int a[110];
int front[110];
int back[110];
int ans;
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
        {
            if(a[i]>a[j]) front[i] = max(front[i] , front[j]+1);
        }
    for(int i = n; i >= 0 ; i--)
        for(int j = n ; j > i; j-- )
        {
            if(a[i] > a[j]) back[i] = max(back[i] , back[j] + 1);
        }
    for(int i = 1; i <= n; i++)
    {
      ans = max(front[i] + back[i], ans);
    }
    cout<<n-ans-1;
    system("pause");
    return 0;
}