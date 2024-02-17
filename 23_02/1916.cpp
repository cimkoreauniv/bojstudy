#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>

struct info
{
    int node, dist;
};

bool operator<(info a, info b)
{
    return a.dist > b.dist;
}

int dist[1010];
std::vector<info> edges[1010];

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int s, e, v;
        scanf("%d %d %d", &s, &e, &v);
        edges[s].push_back({e, v});
    }
    int start, end;
    scanf("%d %d", &start, &end);
    memset(dist, -1, sizeof(dist));
    std::priority_queue<info> pq;
    pq.push({start, 0});
    while (dist[end] == -1)
    {
        int now = pq.top().node;
        int curd = pq.top().dist;
        pq.pop();
        if (dist[now] != -1)
            continue;

        dist[now] = curd;
        for (info edge : edges[now])
            if (dist[edge.node] == -1)
                pq.push({edge.node, curd + edge.dist});
    }
    printf("%d", dist[end]);
    return 0;
}