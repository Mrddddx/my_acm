#include<bits/stdc++.h>
using namespace std;
int block = 2500;
list<vector<char>> List;
typedef list<vector<char>>::iterator it;
it Find(int &pos)
{
    for(it i = List.begin(); ;i++){
        if(i == List.end() || pos <= i ->size()) return i;
        pos -= i ->size();
    }
}
void Insert(int pos, const vector<char> & ch)
{
    it curr = Find(pos);
    if(!List.empty()) Split(curr, pos);
    List.insert(Next(curr), ch);
    Update();
}
void Output(int L, int R)
{

}
int main()
{
    vector<char> ch;
    int len, pos, n;
    cin >> n;
    while(n--)
    {
        char opt[7]; cin >> opt;
        if(opt[0] == 'M') cin >> pos;
        if(opt[0] == 'I') {
            ch.clear();
            cin >> len;
            ch.resize(len);
            for(int i = 0; i < len; i++){
                ch[i] = getchar();
                while (ch[i] < 32 || ch[i] > 126) ch[i] = getchar();
            }
            Insert(pos,ch);
        }

    }
}