#include <stdio.h>
#include <queue>

int main(void)
{
    std::queue<std::pair<int, int>> q;
    int A, B;
    scanf("%d %d", &A, &B);
    q.push({B, 1});
    while (!q.empty())
    {
        int now = q.front().first, cnt = q.front().second;
        q.pop();
        if (now == A)
        {
            printf("%d", cnt);
            return 0;
        }
        if (now % 10 == 1 && now > 1)
            q.push({now / 10, cnt + 1});
        if (now % 2 == 0 && now > 1)
            q.push({now / 2, cnt + 1});
    }
    printf("-1");
    return 0;
}