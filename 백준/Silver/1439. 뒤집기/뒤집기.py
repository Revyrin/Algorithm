n = input()
num = n[0]
cnt = 0
for i in range(1,len(n)):
    if num != n[i]:
        cnt += 1
    num = n[i]

if cnt != 1:
    if cnt % 2 == 0:
        cnt //= 2
    else:
        cnt = cnt // 2 + 1 
print(cnt)