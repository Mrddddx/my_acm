#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    int L,R;
    cin>>L>>R;
    for(int i=L;i<=R;i++)
    {
        int j=i;
        while(j)
        {
            int a=j%10;
            if(a==2) ans++;
            j/=10;
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}