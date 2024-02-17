import itertools
p = itertools.permutations

N, M = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
s = set()
for i in p(l, M):
    s.add(i)

for i in sorted(list(s)):
    print(*i)