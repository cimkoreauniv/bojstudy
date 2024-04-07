#include <stdio.h>
#include <memory.h>

int N, W;
int enemy[10010][2];
// dp[i][j] = i번째를 봤을 때
// j = 0: 모두 채움, 1: 윗줄만 채움, 2: 아랫줄만 채움
int dp[10010][3];

void update(int &lvalue, int rvalue)
{
    if (lvalue > rvalue)
        lvalue = rvalue;
}

void solve(int idx)
{
    update(dp[idx][0], dp[idx - 1][0] + ((enemy[idx][0] + enemy[idx][1] <= W) ? 1 : 2));
    if (idx >= 2 && enemy[idx][0] + enemy[idx - 1][0] <= W && enemy[idx][1] + enemy[idx - 1][1] <= W)
        update(dp[idx][0], dp[idx - 2][0] + 2);

    update(dp[idx][1], dp[idx - 1][0] + 1);
    if (idx >= 1 && enemy[idx][0] + enemy[idx - 1][0] <= W)
        update(dp[idx][1], dp[idx - 1][2] + 1);

    update(dp[idx][2], dp[idx - 1][0] + 1);
    if (idx >= 1 && enemy[idx][1] + enemy[idx - 1][1] <= W)
        update(dp[idx][2], dp[idx - 1][1] + 1);

    update(dp[idx][0], dp[idx][1] + 1);
    update(dp[idx][0], dp[idx][2] + 1);
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &W);
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < N; i++)
                scanf("%d", &enemy[i][j]);
        int ans = 10000000;
        memset(dp, 1, sizeof(dp));
        dp[0][0] = (enemy[0][0] + enemy[0][1] <= W) ? 1 : 2;
        dp[0][1] = dp[0][2] = 1;
        if (N > 1 && enemy[0][0] + enemy[1][0] <= W && enemy[0][1] + enemy[1][1] <= W)
            dp[1][0] = 2;
        for (int i = 1; i < N; i++)
            solve(i);
        update(ans, dp[N - 1][0]);
        if (N > 2)
        {
            if (enemy[0][0] + enemy[N - 1][0] <= W)
            {
                memset(dp, 1, sizeof(dp));
                dp[0][0] = 2;
                dp[0][1] = 1;
                for (int i = 1; i < N; i++)
                    solve(i);
                update(ans, dp[N - 1][2]);
            }
            if (enemy[0][1] + enemy[N - 1][1] <= W)
            {
                memset(dp, 1, sizeof(dp));
                dp[0][0] = 2;
                dp[0][2] = 1;
                for (int i = 1; i < N; i++)
                    solve(i);
                update(ans, dp[N - 1][1]);
            }
            if (enemy[0][0] + enemy[N - 1][0] <= W && enemy[0][1] + enemy[N - 1][1] <= W)
            {
                // printf("start\n");
                memset(dp, 1, sizeof(dp));
                dp[0][0] = 2;
                for (int i = 1; i < N - 1; i++)
                    solve(i);
                update(ans, dp[N - 2][0]);
                // for (int j = 0; j < 3; j++)
                // {
                //     for (int i = 0; i < N; i++)
                //         printf(dp[i][j] == 0x1010101 ? "in " : "%2d ", dp[i][j]);
                //     printf("\n");
                // }
            }
        }

        printf("%d\n", ans);
    }
}