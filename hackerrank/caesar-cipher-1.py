from string import ascii_lowercase, ascii_uppercase

invL = {s:i for i,s in enumerate(ascii_lowercase)}
invU = {s:i for i,s in enumerate(ascii_uppercase)}

n = input()
word = input()
k = int(input())

ans = []
for x in word:
    if x in ascii_lowercase:
        ans.append(ascii_lowercase[(invL[x]+k)%26])
    elif x in ascii_uppercase:
        ans.append(ascii_uppercase[(invU[x]+k)%26])
    else:
        ans.append(x)

print(''.join(ans))