#include <stdio.h>
#include <algorithm>
#include <stack>
#define INF 1000000
char before[10010];
char after[10010];

// ans[i][j]는 인덱스 i까지 맞췄을 때 왼쪽으로 돌아간 횟수의 총합
int ans[10010][10];
int from[10010][10];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 10; j++)
            ans[i][j] = INF;
    scanf("%s", before);
    scanf("%s", after);
    for (int i = 0; i < 10; i++)
        ans[0][i] = i + (before[0] + i - after[0] + 10) % 10;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
            {
                int temp = ans[i - 1][k] + (j - k + 10) % 10 + (before[i] + j - after[i] + 10) % 10;
                if (ans[i][j] > temp)
                {
                    ans[i][j] = temp;
                    from[i][j] = k;
                }
            }
    int minidx = 0;
    for (int i = 1; i < 10; i++)
        if (ans[N - 1][minidx] > ans[N - 1][i])
            minidx = i;
    printf("%d\n", ans[N - 1][minidx]);
    std::stack<std::pair<int, int>> trace;
    for (int i = N - 1; i > 0; i--)
    {
        int k = from[i][minidx];
        if ((before[i] + minidx - after[i] + 10) % 10 != 0)
            trace.push(std::make_pair(i + 1, -(before[i] + minidx - after[i] + 10) % 10));
        if (k != minidx)
            trace.push(std::make_pair(i + 1, (minidx - k + 10) % 10));
        minidx = k;
    }
    if ((before[0] + minidx - after[0] + 10) % 10 != 0)
        trace.push(std::make_pair(1, -(before[0] + minidx - after[0] + 10) % 10));
    if (minidx != 0)
        trace.push(std::make_pair(1, minidx));
    while (!trace.empty())
    {
        printf("%d %d\n", trace.top().first, trace.top().second);
        trace.pop();
    }
    return 0;
}