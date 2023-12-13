n, k = map(int, input().split())
list = [int(input()) for _ in range(n)]

list.sort(reverse=1)
cnt = 0

for i in list:
    if k // i > 0:
        cnt = cnt + k // i
        k %= i

print(cnt)