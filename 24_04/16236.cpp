#include <stdio.h>
#include <memory.h>
#include <queue>

int curx, cury;
int size, left;
int board[30][30];
int ans;

struct node
{
    int dist;
    int x, y;
};

bool solve()
{
    std::queue<node> q;
    bool vis[30][30];
    int dst_x = 29, dst_y = 29;
    memset(vis, 0, sizeof(vis));
    q.push({0, curx, cury});
    vis[cury][curx] = true;
    int min_dist = 999999;
    while (!q.empty() && q.front().dist < min_dist)
    {
        int x = q.front().x, y = q.front().y, dist = q.front().dist;
        // printf("%d %d\n", x, y);
        q.pop();
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (board[ny][nx] <= size && !vis[ny][nx])
            {
                vis[ny][nx] = true;
                q.push({dist + 1, nx, ny});
            }
            if (board[ny][nx] > 0 && board[ny][nx] < size && (ny < dst_y || (ny == dst_y && nx < dst_x)))
            {
                min_dist = dist + 1;
                dst_x = nx, dst_y = ny;
            }
        }
    }
    // printf("%d %d\n", dst_x, dst_y);
    if (board[dst_y][dst_x] >= size)
        return false;
    ans += min_dist;
    board[dst_y][dst_x] = 0;
    curx = dst_x, cury = dst_y;
    left--;
    if (left == 0)
        size++, left = size;
    return true;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            board[i][j] = 999999;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9)
                curx = j, cury = i, board[i][j] = 0;
        }
    size = 2, left = 2;
    while (solve())
        ;
    printf("%d", ans);
    return 0;
}