#include <stdio.h>
#include <memory.h>
#include <queue>

int arr[1010][1010];
int vis[1010][1010];

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    memset(arr, -1, sizeof(arr));
    memset(vis, -1, sizeof(vis));
    std::queue<std::pair<int, int>> q;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                vis[i][j] = 0;
                q.push({j, i});
            }
        }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (vis[ny][nx] == -1 && arr[ny][nx] == 0)
            {
                vis[ny][nx] = vis[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 0 && vis[i][j] == -1)
            {
                printf("-1");
                return 0;
            }
            if (max < vis[i][j])
                max = vis[i][j];
        }
    printf("%d", max);
    return 0;
}