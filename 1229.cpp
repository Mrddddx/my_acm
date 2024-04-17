#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
string positive,flashback;
long long ans;
int main()
{
    cin>>positive>>flashback;
    int len=positive.length()-1;
    for(int i=0;positive[i];i++)
    for(int j=1;flashback[j];j++)
    {
        if(positive[i]==flashback[j]&&positive[i+1]==flashback[j-1]) ans++;
    }
    cout<<(1<<ans);
    system("pause");
    return 0;
}