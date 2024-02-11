#include <stdio.h>
#include <memory.h>
#include <queue>

int arr[110][110][110];
int vis[110][110][110];

struct pos
{
    int x, y, z;
};

int main(void)
{
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);
    memset(arr, -1, sizeof(arr));
    memset(vis, -1, sizeof(vis));
    std::queue<pos> q;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= M; k++)
            {
                scanf("%d", &arr[i][j][k]);
                if (arr[i][j][k] == 1)
                {
                    vis[i][j][k] = 0;
                    q.push({k, j, i});
                }
            }
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        int dx[] = {-1, 1, 0, 0, 0, 0};
        int dy[] = {0, 0, -1, 1, 0, 0};
        int dz[] = {0, 0, 0, 0, -1, 1};

        for (int k = 0; k < 6; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if (vis[nz][ny][nx] == -1 && arr[nz][ny][nx] == 0)
            {
                vis[nz][ny][nx] = vis[z][y][x] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= M; k++)
            {
                if (arr[i][j][k] == 0 && vis[i][j][k] == -1)
                {
                    printf("-1");
                    return 0;
                }
                if (max < vis[i][j][k])
                    max = vis[i][j][k];
            }
    printf("%d", max);
    return 0;
}