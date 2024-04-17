#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int inf=2147483647;
multiset<int> m;
int main()
{
    int q;
    cin>>q;
    m.insert(-inf);
    m.insert(inf);
    for(int i=1;i<=q;i++)
    {
        int op,x;
        cin>>op>>x;
        if(op==1) 
        {
            auto it=m.lower_bound(x);
            int order=0;
            for(auto i=m.begin();i!=it;i++,order++);
            cout<<order<<endl;
        }
        if(op==2)
        {
            int order=-1;
            for(int i:m)
            if(++order==x)
            cout<<i<<endl;
        }
        if(op==3)
        {
            auto it=m.lower_bound(x);
            cout<<*--it<<endl;
        }
        if(op==4)
        {
            cout<<*m.upper_bound(x)<<endl;
        }
        if(op==5)
        {
            m.insert(x);
        }
    }
    system("pause");
    return 0;
}