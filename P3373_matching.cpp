#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    srand(time(0));
    int x;
    int n = rand() % 99 + 2;
    int m = rand() % 100 + 1;
    
    int mod = rand();
    printf("%d %d %d\n", n, m, mod);
    for(int i = 1; i <= n; i++)
        printf("%d ",rand() % 100);
    printf("\n");
    while(m --)
    {
        int op = rand() % 3 + 1;
        int d = rand() % 10 + 1;   
        int L = rand() % n + 1;
        int R = rand() % (n - L + 1) + L - 1; 
        if(op == 3) printf("%d %d %d\n",op,L,R);
        else printf("%d %d %d %d\n",op,L,R,d);
    }
    system("P3373_matching.exe > P3373.txt");
    system("P3373.exe < P3373.txt > P3373_out.txt");
    return 0;
}