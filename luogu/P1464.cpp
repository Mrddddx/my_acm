#include<bits/stdc++.h>
using namespace std;
#define int long long
int m[25][25][25], b[25][25][25];
int f(int x, int y, int z){
    if(x <= 0 || y <= 0 || z <= 0) return 1;
    if(x > 20 || y > 20 || z > 20) return f(20, 20, 20);
    if(b[x][y][z]) return m[x][y][z];
    if(x < y && y < z) 
        m[x][y][z] = f(x, y, z - 1) + f(x, y - 1, z - 1) - (x, y - 1, z);
    else 
        m[x][y][z] = f(x - 1, y, z) + f(x - 1, y - 1, z) + f(x - 1, y, z - 1) - f(x - 1, y - 1, z - 1);
    b[x][y][z] = 1;
    return m[x][y][z];

}
signed main()
{
    int a, b ,c;
    cin >> a >> b >> c;
    while(1){
        if(a == - 1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
        cin >> a >> b >> c;
    }
    system("pause");
    return 0;
}