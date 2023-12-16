exp = input().split('-')

result = sum(map(int, exp[0].split('+')))

for part in exp[1:]:
    result -= sum(map(int, part.split('+')))

print(result)