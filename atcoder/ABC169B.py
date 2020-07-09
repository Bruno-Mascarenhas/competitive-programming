n = int(input())

arr = list(map(int,input().split()))

ans = 1
lim = int(1e18)

if 0 in arr:
    print(0)

else:
    for x in arr:
        ans *= x
        if ans > lim:
            ans = -1
            break 

    print(ans)