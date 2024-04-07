from itertools import combinations

N, M = map(int, input().split())

houses = []
shops = []

for y in range(N):
    for x, v in enumerate(map(int, input().split())):
        if v == 1:
            houses.append((x, y))
        elif v == 2:
            shops.append((x, y))
ans = 10000000
def dist(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])
for choice in combinations(shops, M):
    cnt = 0
    for house in houses:
        cnt += min(map(lambda shop:dist(house, shop), choice))
    ans = min(ans, cnt)
print(ans)