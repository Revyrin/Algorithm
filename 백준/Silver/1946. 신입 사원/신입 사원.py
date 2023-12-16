import sys

read = sys.stdin.readline
t = int(read())
for _ in range(t):
    n = int(read())
    emps = [tuple(map(int, read().split())) for _ in range(n)]
    emps.sort()

    rank = emps[0][1]
    cnt = 1
    for i in emps[1:]:
        if i[1] < rank:
            cnt += 1
            rank = i[1]

    print(cnt)