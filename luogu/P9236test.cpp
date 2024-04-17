#include <bits/stdc++.h> 
using namespace std;
int a[100200];
int n;
int b[101][101];
int Xor[100100]; //前i个数的异或
int main()
{
    cin >> n;
    /*for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }*/
    for (int i = 1; i <= n; i++)
        for (int j = i + 1;j <= n; j++)
    {
        cout << i << '~' << j << ':' << endl;
        for (int ii = i; ii <= j; ii++)
            for (int jj = ii +1; jj <= j; jj++)
            if(ii != jj) 
            {
                cout << 'A' << ii << '^' << 'A' << jj << ' ';
                b[ii][jj] ++;
            }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1;j <= n; j++)
        cout << 'A' << i << 'A' << j << ':' << b[i][j] << endl;
    //1 给定n 异或 A[i][j] 的个数为 i * (n + 1 - j)
    // A[i][j + 1] = i* (n - j)

    //2 A[i][j] = Xor[j]^Xor[j-1]^Xor[i]^Xor[i-1];
    //  A[i][j+1] = Xor[j+1]^Xor[j]^Xor[i]^Xor[i-1];
    //  A[i][j] ^ Xor[j-1] ^ Xor[j+1] = A[i][j+1] = A[i][j] ^ x[j+1]
    //  A[i][j] ^ Xor[j] ^ Xor[j+k] = A[i][j+k] = A[i][i] ^ x[i+k] = x[i+k]
    //  i *A[i][i]
    system("pause");
    return 0;
}