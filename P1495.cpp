#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const long long mod=1000007;
long long n;
long long a,b;
long long ans,maxn1=0x7fffffffffffffff,maxn2;
struct st{
    long long ai,bi;
} num[12];
vector<pair<long long,long long>> haxi[mod+2];
void insert(long long x)
{
    long long hash1=x/mod,hash2=x%mod;
    for(long long i=0;i<haxi[hash2].size();i++)
    {
        if(hash1==haxi[hash2][i].first) 
        {
            haxi[hash2][i].second++;
            if(haxi[hash2][i].second==n) 
            {cout<<x;system("pause");exit(0);}
            break;
        }
    }
    haxi[hash2].push_back(pair<long long,long long>(hash1,1));
    if(haxi[hash2][haxi[hash2].size()-1].second==n) 
            {cout<<x;system("pause");exit(0);}
            
}
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>num[i].ai>>num[i].bi;
    }
    long long chenshu=0;
    do
    {
        int ddq=0;
        for(long long i=1;i<=n;i++)
        {
            int x=chenshu*num[i].ai+num[i].bi;
            if(x<maxn1)
            {  
                //cout<<x<<endl;
                if(x>maxn2) {
                    maxn2=x;
                    ddq++;
                    if(ddq==n) {
                        ddq=0;
                    }
                }
                insert(x);
            }
        }
        chenshu++;
    }while(chenshu);
    cout<<ans;
    system("pause");
    return 0;
}
