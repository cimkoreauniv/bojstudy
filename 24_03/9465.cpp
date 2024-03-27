#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int arr[2][100010], ans[3][100010];

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[0][i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &arr[1][i]);
        for (int i = 1; i <= N; i++)
        {
            ans[0][i] = max(max(ans[0][i - 1], ans[1][i - 1]), ans[2][i - 1]);
            ans[1][i] = max(ans[0][i - 1], ans[2][i - 1]) + arr[0][i];
            ans[2][i] = max(ans[0][i - 1], ans[1][i - 1]) + arr[1][i];
        }
        printf("%d\n", max(ans[0][N], max(ans[1][N], ans[2][N])));
    }
    return 0;
}