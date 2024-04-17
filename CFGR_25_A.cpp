#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int f1,f2;//最后两个1的位置
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int ans = 0;
        f1 = f2 = 0;
        cin >> n;
        cin >> s;
        //n=1和2
        /*if(n == 1) 
        {
            if(s[0] == '1') 
                cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        if(n == 2)
        {
            if(s != "00") 
                cout << "NO\n";
            else cout << "YES\n";
            continue;
        }*/
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                ans++;
                if(f1) f2 = i;
                else f1 = i;
            }
        }
        //cout << ans << endl;
        if(ans % 2 == 1) 
        {
            cout << "NO\n";
            continue;
        }
        if(ans == 2 && abs(f1-f2)==1)
            cout << "NO\n";
        else cout << "YES\n";
    }

    system("pause");
    return 0;
}