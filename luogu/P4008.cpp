#include<bits/stdc++.h>
using namespace std;
int block = 2500;
list<vector<char>> List;
typedef list<vector<char>>::iterator it;
it Find(int &pos)
{
    for(it i = List.begin(); ; i++){
        if(i == List.end() || pos <= i->size()) return i;
        pos -= i->size(); 
    }
}
it Next(it x) {return ++x;}
void Split(it x, int pos)
{
    if(pos == x->size()) return;
    List.insert(Next(x), vector<char>(x->begin() + pos, x->end()));
    x->erase(x->begin() + pos, x->end());
}
void Merge(it x)
{
    x -> insert(x->end(), Next(x)->begin(), Next(x)->end());
    List.erase(Next(x));
}
void Update()
{
    for(it i = List.begin(); i != List.end(); i++){
        while(i->size() >= (block << 1))
            Split(i, i->size() - block);
        while(Next(i) != List.end() && i->size() + Next(i)-> size() <= block)
            Merge(i);
        while(Next(i) != List.end() && Next(i)->empty())
            List.erase(Next(i));
    }
}
void Insert(int pos, const vector<char> &ch)
{
    it curr = Find(pos);
    if(!List.empty()) Split(curr, pos);
    List.insert(Next(curr), ch);
    Update();
}
void Delete(int L, int R)
{
    it Lb, Rb;
    Lb = Find(L); Split(Lb, L);
    Rb = Find(R); Split(Rb, R);
    Rb++;
    while(Next(Lb) != Rb) List.erase(Next(Lb));
    Update();
}
void Output(int L, int R)
{
    it Lb = Find(L), Rb = Find(R);
    for(it it1 = Lb; ; it1++)
    {
        int a; it1 == Lb ? a = L : a = 0;
        int b; it1 == Rb ? b = R : b = it1->size();
        for(int i = a; i < b; i++) putchar(it1->at(i));
        if(it1 == Rb) break;
    }
    putchar('\n');
}
int main()
{
    vector<char> ch;
    int len, pos, n;
    cin >> n;
    while(n--)
    {
        char op[7]; cin >> op;
        if(op[0] == 'M') cin >> pos;
        if(op[0] == 'I') {
            ch.clear();
            cin >> len;
            ch.resize(len);
            for(int i = 0; i < len; i++)
            {
                ch[i] = getchar();
                while(ch[i] < 32 || ch[i] > 126) ch[i] = getchar();
            }
            Insert(pos, ch);
        }
        if(op[0] == 'D') {
            cin >> len;
            Delete(pos, pos + len);
        }
        if(op[0] == 'G') 
        {
            cin >> len;
            Output(pos, pos + len);
        }
        if(op[0] == 'P') pos--;
        if(op[0] == 'N') pos++;
    }
    system("pause");
    return 0;
}