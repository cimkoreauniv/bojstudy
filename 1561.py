N, M = map(int, input().split())

rides = list(map(int, input().split()))

left, right = 0, 2000000000*30

while left <= right:
    t = (left + right) // 2
    n = sum((t + ride - 1) // ride for ride in rides)
    empty = tuple(i+1 for i in range(M) if t % rides[i] == 0)
    if 0 < N-n <= len(empty):
        print(empty[N-n-1])
        break
    elif N-n > len(empty):
        left = t + 1
    else:
        right = t - 1