#include <stdio.h>
#include <memory.h>

int arr[10][10];
bool vis[10][10];

void dfs(int x, int y)
{
    if (vis[y][x] || arr[y][x] == 1)
        return;
    vis[y][x] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arr[i][j] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &arr[i][j]);
    int ans = 0;
    for (int a = 0; a < N * M; a++)
    {
        int ax = a % M + 1, ay = a / M + 1;
        if (arr[ay][ax] != 0)
            continue;
        arr[ay][ax] = 1;
        for (int b = a + 1; b < N * M; b++)
        {
            int bx = b % M + 1, by = b / M + 1;
            if (arr[by][bx] != 0)
                continue;
            arr[by][bx] = 1;
            for (int c = b + 1; c < N * M; c++)
            {
                int cx = c % M + 1, cy = c / M + 1;
                if (arr[cy][cx] != 0)
                    continue;
                arr[cy][cx] = 1;
                memset(vis, 0, sizeof(vis));
                for (int i = 1; i <= N; i++)
                    for (int j = 1; j <= M; j++)
                        if (arr[i][j] == 2 && !vis[i][j])
                            dfs(j, i);
                int cnt = 0;
                for (int i = 1; i <= N; i++)
                    for (int j = 1; j <= M; j++)
                        if (arr[i][j] == 0 && !vis[i][j])
                            cnt++;
                if (ans < cnt)
                    ans = cnt;
                arr[cy][cx] = 0;
            }
            arr[by][bx] = 0;
        }
        arr[ay][ax] = 0;
    }
    printf("%d", ans);
    return 0;
}