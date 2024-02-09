#include <stdio.h>
#define NEGINF -2000000000LL
#define START 131072
typedef long long ll;

ll tree[START * 2]; // max segtree

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

void update(int idx, ll value)
{
    idx = idx + START - 1;
    tree[idx] = value;
    while (idx > 0)
    {
        tree[(idx - 1) / 2] = max(tree[idx], tree[idx % 2 ? idx + 1 : idx - 1]);
        idx = (idx - 1) / 2;
    }
}

int main(void)
{
    int N, D;
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++)
        scanf("%lld", &tree[i + START - 1]);
    for (int i = N + START - 1; i < START * 2; i++)
        tree[i] = NEGINF;
    for (int i = START - 2; i >= 0; i--)
        tree[i] = max(tree[i * 2 + 1], tree[i * 2 + 2]);

    return 0;
}