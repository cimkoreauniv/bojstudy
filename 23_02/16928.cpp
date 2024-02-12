#include <stdio.h>
#include <memory.h>
#include <queue>

int main(void)
{
    int N, M;
    int move[110], vis[110];
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= 100; i++)
        move[i] = i;
    scanf("%d %d", &N, &M);
    int x, y;
    for (int i = 0; i < N + M; i++)
    {
        scanf("%d %d", &x, &y);
        move[x] = y;
    }
    std::queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            if (now + i > 100)
                continue;
            int prev = now + i;
            int next;
            while (true)
            {
                next = move[prev];
                if (next == prev)
                    break;
                prev = next;
            }
            if (vis[next] == -1)
            {
                vis[next] = vis[now] + 1;
                q.push(next);
            }
        }
    }
    printf("%d", vis[100]);
    return 0;
}