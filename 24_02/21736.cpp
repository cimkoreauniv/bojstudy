#include <stdio.h>

char arr[610][610];
int ans;
bool vis[610][610];
void dfs(int x, int y)
{
    if (arr[y][x] == 0 || arr[y][x] == 'X' || vis[y][x])
        return;
    if (arr[y][x] == 'P')
        ans++;
    vis[y][x] = true;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf(" %s", arr[i] + 1);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (arr[i][j] == 'I')
            {
                dfs(j, i);
                if (ans == 0)
                    printf("TT");
                else
                    printf("%d", ans);
                return 0;
            }
}