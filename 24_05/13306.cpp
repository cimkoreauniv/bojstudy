#include <stdio.h>

int parent[200010];
int tree[200010];

int q[400010][3];
int ans[200010], len;

int find(int n)
{
    if (tree[n] == 0)
        return n;
    return tree[n] = find(tree[n]);
}

void merge(int a, int b)
{
    tree[find(a)] = find(b);
}

int main(void)
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N - 1; i++)
        scanf("%d", &parent[i + 2]);
    for (int i = 0; i < N - 1 + Q; i++)
    {
        scanf("%d %d", &q[i][0], &q[i][1]);
        if (q[i][0])
            scanf("%d", &q[i][2]);
    }
    for (int i = N - 2 + Q; i >= 0; i--)
    {
        int a = q[i][0], b = q[i][1], c = q[i][2];
        if (a == 0)
            merge(b, parent[b]);
        else
            ans[len++] = find(b) == find(c);
    }
    for (int i = Q - 1; i >= 0; i--)
        printf(ans[i] ? "YES\n" : "NO\n");
    return 0;
}