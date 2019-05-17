from math import factorial

def comb(n):
    a = factorial(n) / (2 * factorial(n-2))
    return a

n = int(input())

names = []
freq = dict()

for i in range(n):
    names.append(str(input())[0])
    freq[names[i]] = 0

names.sort()
ans = 0
for x in names:
    freq[x]+=1

for x in freq.keys():
    if freq[x] == 1 or freq[x] == 2:
        continue
    elif freq[x] == 3:
        ans+= 1
    elif freq[x] == 4:
        ans+=2
    else:
        ans+= comb(freq[x]//2) + comb(freq[x]//2+freq[x]%2)

print(int(ans))