n = int(input())

fib = [1,1]
for i in range(2,n+2):
    fib.append(fib[i-1]+fib[i-2])

print(fib[n])