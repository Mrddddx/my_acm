#include<bits/stdc++.h>
using namespace std;
stack<int> s;
queue<int> pre;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pre.push(x);
    }
    while(!pre.empty()){
        int x = pre.front(); pre.pop();
        //cout << x;
        if(!s.size()){
            s.push(x);
            continue;
        }
        
        int y = s.top();
        s.push(x);
        while(x == y){
            s.pop();
            s.pop();
            if(!s.size()){
                s.push(x + 1);            
                break;
            }
            y = s.top();
            x++;
            s.push(x);
        }
    }
    cout << s.size();
    system("pause");
    return 0;
}