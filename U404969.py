from math import *
a = input()
a = a.split()
x = int(a[0])
n = int(a[1])
ans = 0
if x == 2 and n > 1:
    print("inf") 
    exit(0)
else:
    if x >= pow(2,n):
        print(ans)
    else:
        n -= 2
        ans = n / (log(x,2) - 1)
    
        ansWer =ceil(log(ans,2))

        print(ansWer)