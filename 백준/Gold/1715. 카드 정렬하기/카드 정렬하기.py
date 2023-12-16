import heapq

n = int(input())
cards = []
for i in range(n):
    heapq.heappush(cards, int(input()))

c_sum = 0

for i in range(n - 1):
    first = heapq.heappop(cards)
    second = heapq.heappop(cards)
    result = first + second
    heapq.heappush(cards, result)
    c_sum += result

print(c_sum)