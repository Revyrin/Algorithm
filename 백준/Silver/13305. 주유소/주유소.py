n = int(input())
dist = list(map(int, input().split()))
oil_prices = list(map(int, input().split()))

price = oil_prices[0]
result = 0

for i in range(n - 1):
    if price > oil_prices[i]:
        price = oil_prices[i]
    result += price * dist[i]

print(result) 