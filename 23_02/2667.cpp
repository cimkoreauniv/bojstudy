#include <stdio.h>
#include <vector>
#include <algorithm>

int arr[30][30];
bool vis[30][30];

int dfs(int x, int y)
{
    if (!arr[x][y] || vis[x][y])
        return 0;
    vis[x][y] = true;
    return 1 + dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%1d", &arr[i][j]);

    std::vector<int> ans;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] && !vis[i][j])
                ans.push_back(dfs(i, j));
        }
    std::sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
}