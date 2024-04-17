#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
double a[N];
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("P1471.txt");
    fout.open("P1471_out1.txt");
    
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    while(m -- )
    {
        int op,  L, R;
        double d, ans = 0;
        double ava = 0;
        fin >> op >> L >> R;
        if(op == 1){
            fin >> d;
            for(int i = L; i <= R; i++)
                a[i] += d;
        }
        else if(op == 2)
        {
            for(int i = L; i <= R; i++)
                ans += a[i];
            ans = ans / (R - L + 1);
            fout << fixed << setprecision(4) << ans << endl;
        }
        else if(op == 3)
        {
            for(int i = L; i <= R; i++)
                ava += a[i];
            ava = ava / (R - L + 1);
            for(int i = L; i <= R; i++)
                ans += (a[i] - ava) * (a[i] - ava);
            ans = ans /(R - L + 1);
            fout << fixed << setprecision(4) << ans << endl;
        }
    }
    //system("pause");
    return 0;
}