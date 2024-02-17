N = int(input())
tree = {}
for i in range(N):
    a, b, c = input().split()
    tree[a] = (b, c)

def pre(n):
    if n=='.':
        return
    print(n, end='')
    pre(tree[n][0])
    pre(tree[n][1])
pre('A')
print()
def _in(n):
    if n=='.':
        return
    _in(tree[n][0])
    print(n, end='')
    _in(tree[n][1])
_in('A')
print()
def post(n):
    if n=='.':
        return
    post(tree[n][0])
    post(tree[n][1])
    print(n, end='')
post('A')
print()