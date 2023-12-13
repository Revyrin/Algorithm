n = int(input())

chg = [500, 100, 50, 10, 5, 1]

s = 1000 - n
cnt = 0

for i in chg:
    if s // i > 0:
        cnt = cnt + s // i
        s %= i

print(cnt)