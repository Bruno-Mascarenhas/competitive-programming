word = input()
ans = 0

for x in word:
    if x.isupper():
        ans+=1

print(ans+1)