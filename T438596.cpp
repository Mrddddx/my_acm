#include<bits/stdc++.h>
using namespace std;
set <int> s;
int n;
int x;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> x;
            s.insert(x);
        }
        if(s.size() == 1)
            cout << n << endl;
        else 
            cout << n - 1 << endl;
        s.clear();
    }
    system("pause");
    return 0;
}