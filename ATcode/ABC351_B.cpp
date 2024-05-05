#include<bits/stdc++.h>
using namespace std;

int main(){
    char A[110][110], B[110][110];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> A[i][j];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {    
            cin >> B[i][j];
            if(B[i][j] != A[i][j]){
                cout << i << ' ' << j;
            }
    }
    system("pause");
    return 0;
}