#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k=15;
    k=k+1^2+2^3+3^4+4^5;
    cout<<k<<endl;
    system("pause");
    k=k+1^2^3+2^3^4+3^4^5;
    cout<<k<<endl;
    system("pause");
    k=k+1^2^3^4+2^3^4^5;
    cout<<k<<endl;
    system("pause");
    k=k+1^2^3^4^5;
    cout<<k<<endl;
    system("pause");
    return 0;
}