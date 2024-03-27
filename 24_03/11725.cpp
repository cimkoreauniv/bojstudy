#include <stdio.h>
#include <vector>

std::vector<int> edges[100010];
int ans[100010];
bool vis[100010];

void dfs(int n)
{
    if (vis[n])
        return;
    vis[n] = true;
    for (int v : edges[n])
    {
        if (!ans[v])
            ans[v] = n;
        dfs(v);
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
        printf("%d\n", ans[i]);
    return 0;
}