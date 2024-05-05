#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n = 0;
    cin >> s;
    for(int i = 3; i <= 5; i++)
    {
        n = n * 10 + s[i] - '0';
    }
    if(s[0] == 'A' && s[1] == 'B' && s[2] == 'C' && n > 0 && n < 350 && n != 316)
        cout << "Yes";
        else cout << "No";
    system("pause");
    return 0;
}