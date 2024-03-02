#include <stdio.h>
#include <memory.h>
#include <vector>

std::vector<int> edges[1010];

bool vis[1010];

void dfs(int n)
{
    if (vis[n])
        return;
    vis[n] = true;
    for (int i = 0; i < edges[n].size(); i++)
        dfs(edges[n][i]);
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    printf("%d", ans);
    return 0;
}