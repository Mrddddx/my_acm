#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int n,m;
int a[N];
int main()
{
    map<int, int> p;
    cin >> n >> m;
    if(n % 2 == 0 && m % 2 == 0) m >>= 1; 
    n <<= 1;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        p[x % m]++;
    }
    int f = 0;
    //cout << p.size();
    for(auto i : p){
        //cout << i.first << ' ';
        if(i.second & 1) {
            f = 1;
            break;
        }
    }
    if(f) cout << "Alice";
    else cout << "Bob";
    system("pause");
	return 0;
}