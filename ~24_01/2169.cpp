#include <stdio.h>

int value[1010][1010];

int ans[1010][1010];
int left[1010][1010];  // 왼쪽에서 올 때
int right[1010][1010]; // 오른쪽에서 올 때

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &value[i][j]);
    ans[1][1] = value[1][1];
    for (int j = 2; j <= M; j++)
        ans[1][j] = ans[1][j - 1] + value[1][j];
    for (int i = 2; i <= N; i++)
    {
        left[i][1] = ans[i - 1][1] + value[i][1];
        for (int j = 2; j <= M; j++)
            left[i][j] = max(left[i][j - 1], ans[i - 1][j]) + value[i][j];
        right[i][M] = ans[i - 1][M] + value[i][M];
        for (int j = M - 1; j >= 1; j--)
            right[i][j] = max(right[i][j + 1], ans[i - 1][j]) + value[i][j];
        for (int j = 1; j <= M; j++)
            ans[i][j] = max(left[i][j], right[i][j]);
    }
    printf("%d", ans[N][M]);
    return 0;
}