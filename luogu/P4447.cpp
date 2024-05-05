#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int M = 1e9 + 10;
struct st{
    int v, num;
} a[N];
int n, cnt;
bool cmp(st x, st y){
    return x.v < y.v;
}
int minn = M;
int q[N];
int  qr;
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].v;
        a[i].num = 1;
    }
    cnt = n;
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 2; i <= n; i++){
        if(a[i].v == a[i - 1].v){
            a[i - 1].v = M;
            a[i].num += a[i - 1].num;
            cnt--;
        }
    }

    sort(a + 1, a + 1 + n, cmp);
    /*for(int i = 1; i <= n; i++)
        cout << a[i].v << ' ';
    cout << endl;
    for(int i = 0; i < a[1].num; i++){
        q[ql + i].push(a[1].v);
    }*/
    qr = 0;
    a[cnt + 1].v = M;
    a[0].v = M;
    //cout << cnt;
    for(int i = 1; i <= cnt + 1; i++){
        if(a[i].v != a[i - 1].v + 1) { //断点
            for(int j = 1; j <=qr; j++){
                minn = min(q[j], minn);
                q[j] = 0;
            }
            qr = 0;
            for(int j = 1; j <= a[i].num; j++){
                qr++;
                q[j]++;
            
            }
            continue;
        }
        if(a[i].num < qr){ //必须舍弃一些了
            for(int j = 1; j <= qr - a[i].num; j++)
                minn = min(q[j], minn);

            for(int j = 1; j <= a[i].num; j++)
                q[j] = q[j + qr - a[i].num] + 1;

            for(int j = a[i].num + 1; j <= qr; j++)
                q[j] = 0;
            qr = a[i].num;
        }
        else if(a[i].num >= qr){//又有新组了
            qr = a[i].num;
            for(int j = 1; j <= qr; j++)
                q[j]++;
        }
        /*for(int i = 1; i <= qr; i++){
            cout << q[i] << ' ';
        }
        cout << endl;*/
    }
    cout << minn;
    system("pause");
    return 0;
}