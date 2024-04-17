#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n, x, op;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> op >> x;
        if(op == 1) seq.insert(lower_bound(seq.begin(), seq.end(), x), x);
        if(op == 2) seq.erase(lower_bound(seq.begin(), seq.end(), x));
        if(op == 3) cout << lower_bound(seq.begin(), seq.end(), x) - seq.begin() + 1 << endl;
        if(op == 4) cout << seq[x - 1] << endl;
        if(op == 5) cout << seq[lower_bound(seq.begin(), seq.end(), x) - seq.begin() - 1 ] << endl;
        if(op == 6) cout << seq[upper_bound(seq.begin(), seq.end(), x) - seq.begin()] << endl;

    }
    system("pause");
    return 0;
}