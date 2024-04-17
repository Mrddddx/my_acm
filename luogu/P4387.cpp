#include <bits/stdc++.h> 
using namespace std;
stack <int> s;
int a[100100],b[100100];//入栈序和出栈序
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int i = 1,j = 1;//i为入栈序的指针,j为出栈序的指针
    while (i <= n)
    {
        if(s.empty()) s.push(a[i]), i++;
            else if(s.top() == b[j]) s.pop(), j++;
                else s.push(a[i]), i++;
    }
    
    while (!s.empty() && s.top() == b[j] ) s.pop(), j++;

    if (s.empty()) cout << "Yes" <<endl;
    else cout << "No" << endl;
    while(!s.empty()) s.pop();
    }
    system("pause");
    return 0;
}