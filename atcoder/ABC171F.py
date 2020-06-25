MOD = int(10e9+7)

def mod(x, m = MOD):
    tmp = x%m 
    if(tmp < 0): tmp += m 
    return tmp

def fpow(x, y, m = MOD):
    res = 1
    while y>0:
        if y%2:
            res =  mod(res*x)
        x = mod(x*x)
        y>>=1
    return res

fat = [1]
ifat = [1]
power25 = [1]

def precalc(lim):
    global fat 
    global ifat 
    global power25

    for i in range(1,lim):
        fat.append(mod(fat[i-1]*i))
        ifat.append(fpow(fat[i], MOD - 2))
        power25.append(mod(25*power25[i-1]))

def comb(n, k):
    return mod(mod(fat[n] * ifat[n-k]) * ifat[k])

k = int(input())
s = input()
n = len(s) + k 

ans = fpow(26,n)
tmp = 0

precalc(n+1)

for m in range(0,len(s)):
    tmp = mod(tmp + mod(fpow(25,n-m)*comb(n,m)))

ans = mod(ans-tmp)

print(ans)