n  = int(input())
arr = input()
arr = [float(x) for x in arr.split()]

diff = sum(arr)/n

diff2 = float(1e15)

for x in arr:
    if abs(diff-x) < diff2:
        diff2 = x

print(diff2)