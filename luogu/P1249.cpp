#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mult = 1;
ll sum = 0;
int a[10086];
int ans[10086];
void solve(int n, int x)
{
  int len = n - 1; //一共n-1个数
  for(int i = 1; i <= len; i++)
    a[i] = i + 1;
 for(int i = len; i > len - x; i--)
    a[i] ++;
  int R = x - len;
  for(int i = len; i >= len - R; i--)
    a[i] ++;
  for(int i = 1; i <= len; i++)
    mult *= a[i];
  for(int i = 1; i <= len; i++)
    cout << a[i] << ' ';
  cout << endl <<mult;
  return;
}
int main()
{
  int n;
  cin >> n;
  if(n <= 4 ) cout << n - 1;
  else
  for(int i = 2; i <= n; i++)
  {
    sum += i;
    if(sum <= n && sum + i + 1 > n) 
    {
      int R = n - sum;
      solve(i, R);
      break;
    } 
  }
  system("pause");
  return 0;
}