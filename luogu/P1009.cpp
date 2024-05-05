#include<bits/stdc++.h>
using namespace std;
int n;
int A[1010], B[1010];
int main()
{
    int n;
    cin >> n;
    A[0] = B[0] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < 1000; j++)
            B[j] *= i;
        for(int j = 0; j < 1000; j++){
            if(B[j] > 9){
                B[j + 1] += B[j] / 10;
                B[j] %= 10;
            }
        }
        for(int j = 0; j < 1000; j++){
            A[j] += B[j];
            if(A[j] > 9){
                A[j + 1] += A[j] / 10;
                A[j] %= 10;
            }
        }
    }
    int i;
    for(i = 1000; i >=0 && A[i] == 0; i--);
    for(int j = i; j >= 0; j--) cout << A[j];
    system("pause");
    return 0;
}