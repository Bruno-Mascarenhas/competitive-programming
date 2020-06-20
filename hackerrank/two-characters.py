from itertools import combinations 
from string import ascii_lowercase

def valid(string):
    ok = len(string) >= 2
    for i in range(1,len(string)):
        ok &= string[i]!=string[i-1]
    return ok

n = input()
word = input()

tries = list(combinations(list(ascii_lowercase),2))
ans = 0

for x,y in tries:
    tmp = ''.join(c for c in word if c in (x,y))

    if valid(tmp):
        ans = max(ans,len(tmp))

print(ans)