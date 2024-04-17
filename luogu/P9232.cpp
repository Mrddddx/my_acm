#include <bits/stdc++.h> 
using namespace std;
string s;
int ans;
int t = 0;
char S[10086];
void init()
{
    
    int len = s.size();
    S[t++] = '&';
    S[t++] = '#';
    for (int i = 0; i < len ; i++)
    {
        S[t++] = s[i];
        S[t++] = '#';
    }
    S[t] = '&';
}
void count()
{
    for(int i = 2; i < t - 1; i++)
    {
        int r = 0;
        int flag = 0;
        while (S[i + r] != '&' && S[i - r] != '&')
        {
            if (S[i + r] == '#') {r++; continue;}
            if (S[i + r]  < S[i - r] ) flag = 1, ans++;
            else if (S[i + r]  == S[i - r] && flag == 1) ans++;
            else if (S[i + r]  > S[i - r]) flag = 0; 
            //cout << S[i + r]  << S[i - r];
            r++;
        }
    }
}

int main()
{
    cin >> s;
    init();
    count();
    cout << ans;
    system("pause");
    return 0;
}