#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>

int board[110][110];
int vis[110][110];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    memset(board, -1, sizeof(board));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &board[i][j]);
    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    vis[1][1] = 1;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int curday = 0;
    while (true)
    {
        std::vector<std::pair<int, int>> next;
        while (!q.empty())
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = q.front().first + dx[k], ny = q.front().second + dy[k];
                if (board[ny][nx] == 0 && vis[ny][nx] == 0)
                    q.push({nx, ny}), vis[ny][nx] = 1;
                else if (board[ny][nx] == 1 && vis[ny][nx] < 2)
                {
                    vis[ny][nx]++;
                    if (vis[ny][nx] == 2)
                        next.push_back({nx, ny});
                }
            }
            q.pop();
        }
        if (next.size() == 0)
        {
            printf("%d", curday);
            return 0;
        }
        for (auto p : next)
            q.push(p);
        curday++;
    }
    return 0;
}