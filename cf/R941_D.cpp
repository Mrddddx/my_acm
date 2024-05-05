#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
void solve(){
    queue<int> q;
    int n, k;
    cin >> n >> k;
    int i = 1;
    int j = 25;

    while(!((1 << j) & k)) {j--;}
    //cout << j;
    for(int ii = 0; ii < j; ii ++){
        q.push(1 << ii);
    }
    
    if(k != 1 << j) q.push(k - (1 << j));
    if(k + 1 <= n) 
        if(k != 1) q.push(k + 1);
        else q.push(k + 2);
    while(k << i <= n){
        q.push(k << i);
        if(i == 1) q.push( k * 3);
        i++;
    }
    cout << q.size() << '\n';
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout <<'\n';
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}