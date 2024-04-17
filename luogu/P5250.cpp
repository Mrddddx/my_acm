#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<set>
using namespace std;
set <int> mood;
int n,m,q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>q;
        if(m==1) 
            if(mood.find(q)!=mood.end()) 
                cout<<"Already Exist"<<endl;
            else{
               mood.insert(q);
            }
        else 
            if(mood.empty()) cout<<"Empty"<<endl;
            else 
            {
                auto l=mood.lower_bound(q),u=l;
                if(l!=mood.begin()) l--;
                if(u!=mood.end()&& q-*l>*u-q) l=u;
                cout<<(*l)<<endl;
                mood.erase(*l);
            }
    }
    system("pause");
    return 0;
}
