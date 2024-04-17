#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int n;//变量数
string s;
char a[10];//存变量
int main(){
    cout<<"请输入你的变量：\n";
    getline(cin,s);//cin会被逗号隔开
    for(int i=0;i<s.size();i++)
    if(s[i]!=' ') a[n++]=s[i];
    for(int i=0;i<n;i++)
    cout<<a[i];
    cout<<"请输入你的合式公式：\n";
    cin>>s;
    
    system("pause");
    return 0;
}