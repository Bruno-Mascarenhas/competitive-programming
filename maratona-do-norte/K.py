n = int(input(),2)
i = int(input())
divs = []
for _ in range(i):
    j = int(input())
    if(n%j==0):
        divs.append(j)
divs.sort()
if len(divs) == 0:
    print("Nenhum")
else:
    for i in range(len(divs)-1):
        print(divs[i],end=' ')
    print(divs[-1])