#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int a[N];
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("P3870.txt");
    fout.open("P3870_out1.txt");
    
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        a[i] = 0;
    while(m -- )
    {
        int op, ans = 0, L, R;
        fin >> op >> L >> R;
        if(!op)
            for(int i = L; i <= R; i++)
                a[i] ^= 1;
        else {
            for(int i = L; i <= R; i++)
                if(a[i]) ans ++;
            fout << ans << endl;
        }
    }
    system("pause");
    return 0;
}