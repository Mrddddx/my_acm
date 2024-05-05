#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
void dfs(int x){
    int i = 20;
    while(i > 1){
        if((1 << i) & x) {
            cout << "2(";
            dfs(i);
            x -= (1 << i);
            if(!x)  cout << ')';
            else cout << ")+";
        } 
        i--;
    }
    if(x == 3) cout << "2+2(0)";
    if(x == 2) cout << 2;
    if(x == 1) cout << "2(0)";
}
int main()
{
    int n;
    cin >> n;
    dfs(n);
    system("pause");
    return 0;
}