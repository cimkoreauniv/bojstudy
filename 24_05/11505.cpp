#include <stdio.h>
#define MID ((left + right) / 2)
#define MOD 1000000007
typedef long long ll;

ll tree[2100000];
ll input[1000010];

ll init(int node, int left, int right)
{
    if (left == right)
        return tree[node] = input[left];
    return tree[node] = (init(node * 2 + 1, left, MID) * init(node * 2 + 2, MID + 1, right)) % MOD;
}

void update(int node, int left, int right, int target, ll _new)
{
    if (left > target || right < target)
        return;
    if (left == right)
    {
        tree[node] = _new;
        return;
    }
    update(node * 2 + 1, left, MID, target, _new);
    update(node * 2 + 2, MID + 1, right, target, _new);
    tree[node] = (tree[node * 2 + 1] * tree[node * 2 + 2]) % MOD;
}

ll solve(int node, int left, int right, int s, int e)
{
    if (s <= left && right <= e)
        return tree[node];
    else if (s > e || e < left || right < s)
        return 1LL;
    return (solve(node * 2 + 1, left, MID, s, e) * solve(node * 2 + 2, MID + 1, right, s, e)) % MOD;
}

int main(void)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++)
        scanf("%lld", &input[i]);
    init(0, 0, N - 1);
    for (int i = 0; i < M + K; i++)
    {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1)
        {
            b--; // b starts from 1, index starts from 0
            ll old = input[b];
            input[b] = c;
            update(0, 0, N - 1, b, c);
        }
        else
        {
            // b, c starts from 1, index starts from 0
            b--;
            c--;
            printf("%lld\n", solve(0, 0, N - 1, b, (int)c));
        }
    }
    return 0;
}