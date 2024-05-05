#include<bits/stdc++.h>
using namespace std;
const int M = 1e6 + 1e5 + 10;
int cnt;
struct Node{
    int ls, rs;
    int key, pri;
    int size;
} t[M];
void newNode(int x){
    cnt ++;
    t[cnt].size = 1;
    t[cnt].ls = t[cnt].rs = 0;
    t[cnt].key = x;
    t[cnt].pri = rand();
}
void update(int u){
    t[u].size = t[t[u].ls].size + t[t[u].rs].size + 1;
}
void rotate(int &o, int d){
    int k;
    if(d == 1){ //左旋
        k = t[o].rs;
        t[o].rs = t[k].ls;
        t[k].ls = o;
    }
    else {
        k = t[o].ls;
        t[o].ls = t[k].rs;
        t[k].rs = o;
    }
    t[k].size = t[o].size;
    update(o);
    o = k;
}
void Insert(int &u, int x){
    if(u == 0) {
        newNode(x);
        u = cnt;
        return;
    }
    t[u].size++;
    if(x >= t[u].key) Insert(t[u].rs, x);
    else              Insert(t[u].ls, x);
    if(t[u].ls != 0 && t[u].pri > t[t[u].ls].pri) rotate(u, 0);
    if(t[u].rs != 0 && t[u].pri > t[t[u].rs].pri) rotate(u, 1);
    update(u);
}
void Del(int &u, int x){
    t[u].size--;
    if(t[u].key == x){
        if(t[u].ls == 0 && t[u].rs == 0) {u = 0; return;}
        if(t[u].ls == 0 || t[u].rs == 0) {u = t[u].ls + t[u].rs; return;}
        if(t[t[u].ls].pri < t[t[u].rs].pri){
            rotate(u, 0);
            Del(t[u].rs, x);
            return;
        }
        else {
            rotate(u, 1);
            Del(t[u].ls, x);
            return;
        }
    }
    if(t[u].key > x) Del(t[u].ls, x);
    else Del(t[u].rs, x);
    update(u);
}
int Rank(int u, int x){
    if(u == 0) return 0;
    if(x > t[u].key) return t[t[u].ls].size + 1 + Rank(t[u].rs, x);
    return Rank(t[u].ls, x);
}
int Kth(int u, int k){
    if(k == t[t[u].ls].size + 1) return t[u].key;
    if(k > t[t[u].ls].size + 1) return Kth(t[u].rs, k - t[t[u].ls].size - 1);
     if(k < t[t[u].ls].size + 1) return Kth(t[u].ls, k);

}
int Pre(int u, int x){
    if(u == 0) return 0;
    if(t[u].key >= x) return Pre(t[u].ls, x);
    int tmp = Pre(t[u].rs, x);
    if(tmp == 0) return t[u].key;
    return tmp;
}
int Suc(int u, int x){
    if(u == 0) return 0;
    if(t[u].key <= x) return Suc(t[u].rs, x);
    int tmp = Suc(t[u].ls, x);
    if(tmp == 0) return t[u].key;
    return tmp;
}
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{
    srand(time(NULL));
    int root = 0;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x = read();
        Insert(root, x);
    }
    int last = 0;
    int ans = 0;
    while(m--){
        int op, x; 
        op = read(); x = read();
        x ^= last; 
        switch(op){
            case 1: Insert(root, x);    break;
            case 2: Del(root, x);       break;
            case 3: last = Rank(root, x) + 1; ans ^= last;  break;
            case 4: last = Kth(root, x); ans ^= last;  break;
            case 5: last = Pre(root, x); ans ^= last;  break;
            case 6: last = Suc(root, x); ans ^= last;  break;
       }
    }
    cout << ans;
    system("pause");
    return 0;
}