base = 'SOS'

word = input()

ans = base * (len(word)//3)

print(sum([1 if x != y else 0 for x,y in zip(word,ans)]))