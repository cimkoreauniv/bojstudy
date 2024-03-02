#include <stdio.h>
#include <vector>
#define INF 2000000000

struct edge
{
    int to, val;
};

std::vector<edge> edges[100010];

int ans = 0;

int max(int a, int b)
{
    return a > b ? a : b;
}

int get_max_line(int node, int parent)
{
    int max1 = 0, max2 = 0;
    for (int i = 0; i < edges[node].size(); i++)
    {
        if (edges[node][i].to == parent)
            continue;
        int val = get_max_line(edges[node][i].to, node) + edges[node][i].val;
        if (val > max1)
            max2 = max1, max1 = val;
        else if (val > max2)
            max2 = val;
    }
    ans = max(ans, max1 + max2);
    return max1;
}

int main(void)
{
    int V;
    scanf("%d", &V);
    for (int i = 0; i < V; i++)
    {
        int node;
        scanf("%d", &node);
        while (true)
        {
            int a, b;
            scanf("%d", &a);
            if (a == -1)
                break;
            scanf("%d", &b);
            edges[node].push_back({a, b});
        }
    }
    get_max_line(1, 0);
    printf("%d", ans);
    return 0;
}