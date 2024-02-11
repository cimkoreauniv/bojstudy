#include <stdio.h>
#include <memory.h>
char grid[110][110];
bool vis[110][110];

void dfs(int x, int y, char origin)
{
    if (vis[x][y] || grid[x][y] != origin)
        return;
    vis[x][y] = true;
    dfs(x - 1, y, origin);
    dfs(x + 1, y, origin);
    dfs(x, y - 1, origin);
    dfs(x, y + 1, origin);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%s", grid[i] + 1);

    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (!vis[i][j])
            {
                dfs(i, j, grid[i][j]);
                cnt++;
            }
    printf("%d ", cnt);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (grid[i][j] == 'G')
                grid[i][j] = 'R';
    cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (!vis[i][j])
            {
                dfs(i, j, grid[i][j]);
                cnt++;
            }
    printf("%d", cnt);
    return 0;
}