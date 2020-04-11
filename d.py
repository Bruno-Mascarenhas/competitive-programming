n, k = [int(x) for x in str(input()).split()]
arr = [int(x) for x in str(input()).split()]

psum,ans = [arr[0]], 0
for x in range(1,len(arr)):
    psum.append(arr[x]+psum[-1])
psum.sort(reverse=True)
ans = sum(psum)
for x in range(0,k-1):
    ans-=psum[x]
print(ans)