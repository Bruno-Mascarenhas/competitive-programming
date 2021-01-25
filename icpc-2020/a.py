import random 

n, a, b = [int(x) for x in input().split()]
res = 0

for i in range(1,10000):
    ans, cnt = 0, 0
    while cnt < n:
        cnt += random.randint(a,b)
        ans +=1
    
    res = (res*i+ans)/(i+1)

print(res)
