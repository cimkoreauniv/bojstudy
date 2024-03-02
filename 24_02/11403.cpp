#include <stdio.h>
#include <memory.h>
#include <vector>

int adj[110][110], ans[110][110];
int N;
bool vis[110];

std::vector<int> nodes;
void dfs(int n)
{
    for (int i = 0; i < N; i++)
        if (!vis[i] && adj[n][i])
        {
            vis[i] = true;
            nodes.push_back(i);
            dfs(i);
        }
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &adj[i][j]);
    for (int i = 0; i < N; i++)
    {
        memset(vis, 0, sizeof(vis));
        nodes.clear();
        dfs(i);
        for (int n1 : nodes)
            ans[i][n1] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}