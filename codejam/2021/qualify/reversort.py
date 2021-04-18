t = int(input())

for case in range(1,t+1):
    n = int(input())
    arr = [int(x) for x in input().split()]

    cost = 0
    for i in range(len(arr)-1):
        j = i
        for k in range(i+1,n):
            if arr[k] < arr[j]:
                j = k
        cost += j-i+1
        arr[i:j+1] = reversed(arr[i:j+1])

    print(f'Case #{case}: {cost}')