#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++){
        
        cin >> x;
        seq.insert(upper_bound(seq.begin(), seq.end(), x), x);
        if(i & 1)
            cout << seq[i >> 1] << endl; 
    }    
    system("pause");
    return 0;
}