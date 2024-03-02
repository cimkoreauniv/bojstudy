#include <stdio.h>
#include <queue>

struct info
{
    int x, y;
    int state;
};

char board[30][30];

int countone(int n)
{
    int ret = 0;
    for (int i = 0; i < 26; i++)
        ret += n & (1 << i) ? 1 : 0;
    return ret;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++)
        scanf(" %s", board[i] + 1);
    std::queue<info> q;
    q.push({1, 1, 1 << (board[1][1] - 'A')});
    int ans = 0;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, state = q.front().state;
        ans = max(ans, countone(state));
        q.pop();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (board[ny][nx] == 0 || (state & (1 << (board[ny][nx] - 'A'))))
                continue;
            q.push({nx, ny, state | (1 << (board[ny][nx] - 'A'))});
        }
    }
    printf("%d", ans);
    return 0;
}