import re
from string import ascii_lowercase
stop = [x.lower() for x in input().split(';')]
idterms = input().split(';')
idterms = {term.lower():0 for term in idterms}

def isWord(word):
    valid = list(ascii_lowercase)+['\'']
    ok = True
    for x in word:
        ok &= (x in valid and x not in stop)
    return (ok and word not in stop)

ans = []
teste = 0

while 1:
    try:
        x = input()
        teste += sum([1 if isWord(el) else 0 for el in x.split()])        
        parsed = re.split('[ ?!.,>]',x)
        for x in parsed:
            if len(x)>0:
                if '</' in x:
                    ans.append(x.split('</')[0])
                    ans.append(x[x.find('</'):])
                else:
                    ans.append(x)
    except EOFError:
        break

title = abstract = body = False
values = {'<title':5, '<abstract':3, '<body':1}
special = ['<title', '</title','<abstract','</abstract','<body','</body']
total = 0

cur = []
for el in ans:
    tmp = el 
    el = el.lower()

    if el in special:
        if special.index(el)%2 == 0:
            cur.append(special[special.index(el)])
            teste -=1
        else:
            cur.pop()

    elif len(cur)>0:
        if el in stop or len(el.split('<'))>1:
            continue

        if el in idterms.keys():
            idterms[el] += values[cur[0]]
            teste -=1
        
        total+=1

scores = []
for key, val in idterms.items():
    scores.append((key, val/teste*100))
mp = sorted(scores,key=lambda x: (x[1],x[0]), reverse=True )

for i in range(min(3,len(mp))):
    print('{}: {:.9f}'.format(mp[i][0], mp[i][1]))

#print(teste)
#print(idterms)
#print(total)
#print(mp)