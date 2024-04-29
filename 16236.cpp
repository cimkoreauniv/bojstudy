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
    while (!q.empty())
    {
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        int x = q.front().x, y = q.front().y, dist = q.front().dist;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (board[ny][nx] < size &&)
        }
    }
    if (dst_x == 0 && dst_y == 0)
        return false;
    left--;
    if (left == 0)
        size++, left = size;
    return true;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    memset(board, -1, sizeof(board));
    board[29][29] = 999999;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9)
                curx = j, cury = i;
        }
    size = 2, left = 2;
    while (solve())
        ;
    printf("%d", ans);
    return 0;
}