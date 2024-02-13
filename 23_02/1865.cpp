#include <stdio.h>
#define INF 1000000000

int dist[510];

int from[5200], to[5200], t[5200];

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, M, W;
        scanf("%d %d %d", &N, &M, &W);
        int i;
        for (i = 0; i < M * 2; i += 2)
        {
            scanf("%d %d %d", &from[i], &to[i], &t[i]);
            from[i + 1] = to[i], to[i + 1] = from[i], t[i + 1] = t[i];
        }
        for (; i < M * 2 + W; i++)
            scanf("%d %d %d", &from[i], &to[i], &t[i]), t[i] = -t[i];
        for (int i = 1; i <= N; i++)
            dist[i] = INF;
        for (int i = 0; i < N - 1; i++)
            for (int e = 0; e < M * 2 + W; e++)
                if (dist[to[e]] > dist[from[e]] + t[e])
                    dist[to[e]] = dist[from[e]] + t[e];
        bool flag = false;
        for (int e = 0; e < M * 2 + W; e++)
            if (dist[to[e]] > dist[from[e]] + t[e])
            {
                flag = true;
                break;
            }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}