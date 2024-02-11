#include <stdio.h>
#include <iostream>

char str[2010];
// cnt[i][j] = 왼쪽 상단이 B일때 왼쪽 상단(1, 1)부터 (i, j)까지 체스판에 부합하는 알파벳의 개수
int cnt[2010][2010];
int min(int a, int b)
{
    return a < b ? a : b;
}
int main(void)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", str);
        for (int j = 1; j <= M; j++)
        {
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            cnt[i][j] += (str[j - 1] == 'B') ^ ((i + j) % 2);
        }
    }
    int ans = 100000000;
    for (int i = 1; i <= N - K + 1; i++)
        for (int j = 1; j <= M - K + 1; j++)
        {
            int change = cnt[i + K - 1][j + K - 1] + cnt[i - 1][j - 1] - cnt[i + K - 1][j - 1] - cnt[i - 1][j + K - 1];
            ans = min(ans, min(change, K * K - change));
        }
    printf("%d", ans);
    return 0;
}