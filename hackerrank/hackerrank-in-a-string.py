n = int(input())
string = 'hackerrank'

for _ in range(n):
    word = input()
    j = 0

    for i in range(len(word)):
        if j < len(string) and word[i] == string[j]:
            j+=1

    print("{}".format("YES" if j == len(string) else "NO"))