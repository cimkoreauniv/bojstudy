#include <stdio.h>
#define INF 100000

int item[110];
int dist[110][110];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(void)
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d", &item[i]);
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 110; j++)
            dist[i][j] = i == j ? 0 : INF;
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            if (dist[i][j] <= m)
                sum += item[j];
        if (ans < sum)
            ans = sum;
    }
    printf("%d", ans);
    return 0;
}