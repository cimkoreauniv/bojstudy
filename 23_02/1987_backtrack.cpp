#include <stdio.h>

char board[30][30];

int ans = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool vis[30];
void solve(int x, int y, int depth)
{
    if (ans < depth)
        ans = depth;
    vis[board[y][x] - 'A'] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (board[ny][nx] && !vis[board[ny][nx] - 'A'])
            solve(nx, ny, depth + 1);
    }
    vis[board[y][x] - 'A'] = false;
}

int main(void)
{
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++)
        scanf(" %s", board[i] + 1);
    solve(1, 1, 1);
    printf("%d", ans);
    return 0;
}