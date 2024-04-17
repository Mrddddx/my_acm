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
    for(int i = 1; i <= n; i++)
        printf("%d ",rand() % 100);
    printf("\n");
    while(m --)
    {
        int op = rand() % 3 + 1;
        int d = rand() % 10;   
        int L = rand() % n + 1;
        int R = rand() % (n - L + 1) + L - 1; 
        if(op != 1) printf("%d %d %d\n",op,L,R);
        else printf("%d %d %d %d\n",op,L,R,d);
    }
    system("P1471_matching.exe > P1471.txt");
    system("P1471.exe < P1471.txt > P1471_out.txt");
    return 0;
}