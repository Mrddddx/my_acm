#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll a[N];
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("P3373.txt");
    fout.open("P3373_out1.txt");
    
    int n, m, mod;
    fin >> n >> m >> mod;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    while(m -- )
    {
        int op,  L, R;
        ll d, ans = 0;
        ll ava = 0;
        fin >> op >> L >> R;
        if(op == 1){
            fin >> d;
            for(int i = L; i <= R; i++)
                a[i] *= d,a[i] %= mod;
        }
        else if(op == 2)
        {
            fin >> d;
            for(int i = L; i <= R; i++)
                a[i] += d, a[i]%= mod;
        }
        else if(op == 3)
        {
            for(int i = L; i <= R; i++)
                ans += a[i], ans%= mod;
            fout << ans << endl;
        }
    }
    //system("pause");
    return 0;
}