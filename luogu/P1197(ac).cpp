#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 200005
using namespace std;
int n,m,fa[MAXN*2],K,D[MAXN*2],vis[MAXN*2],ans[2*MAXN],num;


struct st{
    int x,y,c; 

}a[MAXN];
bool cmp(st x, st y)
{
    return x.c < y.c;
}

int father(int x)
{
    return fa[x]==x?x:fa[x]=father(fa[x]);
}
void mer(int x,int y){
    int fx = father(x), fy = father(y);
    if(fx != fy)  fa[fx]=fy, num--;
}
int main(){
    cin >> n >> m; num=n;
    for(int i = 0; i < n; i++) fa[i] = i;
    
    for(int i = 1; i <= m; i++) 
        cin >> a[i].x >> a[i].y;
    
    cin >> K;
    for(int i = 1; i <= K; i++){
        cin >> D[i];
        vis[D[i]] = K - i + 1;//给点标号，从大到小
    } 
    for(int i = 1; i <= m; i++) 
        a[i].c = max(vis[a[i].x], vis[a[i].y]); 
    sort(a + 1, a + 1 + m, cmp); 
    for(int i = 0, j = 1; i <= K; i++){ 
        for(;a[j].c == i; j++) mer(a[j].x, a[j].y);//将当前序号全部合并 
        ans[i] = num - (K - i);
        
    }

    
    for(int i = K; i >= 0; i--) 
        cout << ans[i] << endl;
        system("pause");
    return 0;
}