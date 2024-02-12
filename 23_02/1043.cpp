#include <stdio.h>

bool adj[51][51];
bool vis[51];

int N, M;

int len[50];
int party[50][50];

void dfs(int n)
{
    for (int i = 1; i <= N; i++)
        if (adj[n][i] && !vis[i])
        {
            vis[i] = true;
            dfs(i);
        }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    int vlen;
    scanf("%d", &vlen);
    for (int i = 0; i < vlen; i++)
    {
        int p;
        scanf("%d", &p);
        vis[p] = true;
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &len[i]);
        for (int j = 0; j < len[i]; j++)
            scanf("%d", &party[i][j]);
        for (int j = 0; j < len[i]; j++)
            for (int k = j + 1; k < len[i]; k++)
            {
                int a = party[i][j], b = party[i][k];
                adj[a][b] = adj[b][a] = true;
            }
    }
    for (int i = 1; i <= N; i++)
        if (vis[i])
            dfs(i);
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        bool flag = true;
        for (int j = 0; j < len[i]; j++)
            if (vis[party[i][j]])
            {
                flag = false;
                break;
            }
        if (flag)
            ans++;
    }
    printf("%d", ans);
}