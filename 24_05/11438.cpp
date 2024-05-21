#include <stdio.h>
#include <vector>

int N, M;
std::vector<int> edges[100010];
int parents[100010][18]; // 2**17 = 131,072
int depth[100010];

bool vis[100010];
int node_list[100010];
void build_parents(int node, int n_depth)
{
    if (vis[node])
        return;
    vis[node] = true;
    node_list[n_depth] = node;
    depth[node] = n_depth;
    int l = 0, r = n_depth - 1;
    int len = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        parents[node][len++] = node_list[mid];
        l = mid + 1;
    }
    for (int i : edges[node])
        build_parents(i, n_depth + 1);
}

int LCA(int a, int b)
{
    while (depth[a] > depth[b])
    {
        for (int i = 0; parents[a][i]; i++)
            if (depth[parents[a][i]] >= depth[b])
            {
                a = parents[a][i];
                break;
            }
    }
    while (depth[a] < depth[b])
    {
        for (int i = 0; parents[b][i]; i++)
            if (depth[a] <= depth[parents[b][i]])
            {
                b = parents[b][i];
                break;
            }
    }
    if (a == b)
        return a;
    int ret = a;
    while (true)
    {
        bool flag = true;
        for (int i = 0; parents[a][i]; i++)
            if (parents[a][i] != parents[b][i])
            {
                flag = false;
                a = parents[a][i], b = parents[b][i];
                break;
            }
            else
                ret = parents[a][i];
        if (flag)
            break;
    }
    return ret;
}

int main(void)
{
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    build_parents(1, 0);
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}