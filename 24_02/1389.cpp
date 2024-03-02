#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>

std::vector<int> edges[110];
int vis[110];

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
    int ans = 0, maxval = 100000;
    for (int i = 1; i <= N; i++)
    {
        std::queue<int> q;
        memset(vis, -1, sizeof(vis));
        q.push(i);
        vis[i] = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < edges[cur].size(); j++)
            {
                int next = edges[cur][j];
                if (vis[next] == -1)
                {
                    vis[next] = vis[cur] + 1;
                    q.push(next);
                }
            }
        }
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += vis[j];
        if (sum < maxval)
        {
            maxval = sum;
            ans = i;
        }
    }
    printf("%d", ans);
    return 0;
}