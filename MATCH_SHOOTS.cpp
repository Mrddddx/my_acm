#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    srand(time(0));
    int x;
    int n = rand() % 99 + 2;
    int m = rand() % 100 + 1;
    printf("%d %d\n", n, m);
    while(m --)
    {
        int op = rand() % 2;   
        int L = rand() % n + 1;
        int R = rand() % (n - L + 1) + L - 1; 
        printf("%d %d %d\n",op,L,R);
    }
    system("MATCH_SHOOTS.exe > P3870.txt");
    system("P3870(baoli).exe < P3870.txt > P3870_out.txt");
    system("pause");
    return 0;
}