#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> edges[110];
bool vis[110];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // BFS starting from 1
    std::queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < edges[node].size(); i++)
        {
            int next = edges[node][i];
            if (!vis[next])
            {
                q.push(next);
                vis[next] = true;
            }
        }
    }
    // count number of nodes visited
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (vis[i])
            cnt++;
    printf("%d", cnt - 1);
    return 0;
}