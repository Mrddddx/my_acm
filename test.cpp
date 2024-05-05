#include<iostream>

using namespace std;
int n = (1 << 31) - 1;
long long  ans ;
int main()
{

    while(1){
        ans += n;
        cout << ans << endl;
    system("pause");
    }
    return 0;
}