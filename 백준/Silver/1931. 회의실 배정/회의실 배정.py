n = int(input())
times = [tuple(map(int, input().split())) for _ in range(n)]

times.sort(key=lambda x:(x[1],x[0]))

end_time = 0
cnt = 0

for time in times:
    start, end = time
    if start >= end_time:
        end_time = end
        cnt += 1    

print(cnt)