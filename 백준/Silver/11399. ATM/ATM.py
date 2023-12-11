n = int(input())
list = list(map(int, input().split()))

list.sort()

waiting_t = 0
total_t = 0

for i in list:
    waiting_t += i
    total_t += waiting_t

print(total_t)