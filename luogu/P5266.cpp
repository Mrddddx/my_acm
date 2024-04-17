#include<iostream>
#include<cstdlib>
#include<map>
#include<string>
using namespace std;

int n;
string name;
map<string,int> a;

int main()
{
    cin>>n;
    int k;
    for(int I=1;I<=n;I++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            cin>>name>>k;
            a[name]=k;
            cout<<"OK"<<endl;
        }
        if(op==2)
        {
            cin>>name;
            if(a.find(name)!=a.end())
            {
                cout<<a[name]<<endl;
            }
            else cout<<"Not found"<<endl;
        }
        if(op==3)
        {
            cin>>name;
            if(a.find(name)!=a.end())
            {
                a.erase(a.find(name));
                cout<<"Deleted successfully"<<endl;
            }
            else cout<<"Not found"<<endl;
        }
        if(op==4)
        {
            cout<<a.size()<<endl;
        }
    
    }
    system("pause");
    return 0;
}