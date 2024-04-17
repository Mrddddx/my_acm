T = input()
T = int (T)
while T != 0:
    T -=1
    n = input()
    n = int(n)
    ans =n*(n+1)*(2*n+1)//6 % 998244353  
    print(ans)