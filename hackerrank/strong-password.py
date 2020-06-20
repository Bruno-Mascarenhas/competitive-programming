n = input()
word = input()

digit = lower = upper = especial = 1

for x in word:
    if x.isupper():
        upper = 0
    elif x.islower():
        lower = 0
    elif x.isdigit():
        digit = 0
    elif x in '!@#$%^&*()-+':
        especial = 0

ans = upper + lower + digit + especial

if len(word) + ans < 6:
    ans = max(ans,6 - len(word))

print(ans)