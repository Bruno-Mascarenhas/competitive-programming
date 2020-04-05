import json
from operator import itemgetter

years = ("2018", "2017")

arts = {}
n = int(input())
pubs = json.loads(input())
#print(pubs)
for p in pubs["publications"]:
    arts[p["publicationNumber"]] = [p["publicationTitle"], 0, 0]
    for ac in p["articleCounts"]:
        if ac["year"] in years:
            arts[p["publicationNumber"]][1] += int(ac["articleCount"])
for i in range(1, n):
    p = json.loads(input())
    arr = p["paperCitations"]["ieee"]
    for c in arr:
        num = c["publicationNumber"]
        if num not in arts:
            continue
        if c["year"] in years:
            arts[num][2] += 1
output = [(i[2]/i[1], i[0]) for i in arts.values()]

#output = list(reversed(sorted(output)))
output = list(sorted(output,key=itemgetter(1,2)))

for o in output:
    print("%s: %.2f" % (o[1], o[0]))