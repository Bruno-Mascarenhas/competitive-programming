a,b = input().split()

a = int(a)

ans = 0
ans += int(b[0])*100
ans += int(b[2])*10
ans += int(b[3])

print((ans*a)//100)