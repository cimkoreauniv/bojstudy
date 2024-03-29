#include <stdio.h>
#include <memory.h>
#include <queue>

struct element
{
    int time, cnt;
} vis[100010];

int main(void)
{
    int N, K;
    std::queue<int> q;
    scanf("%d %d", &N, &K);
    vis[N] = {0, 1};
    q.push(N);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (vis[K].cnt > 0 && vis[now].time >= vis[K].time)
            break;
        int nowtime = vis[now].time, nowcnt = vis[now].cnt;
        int targets[] = {now - 1, now + 1, now * 2};
        int check[] = {now > 0, now < 100000, now <= 50000};
        for (int i = 0; i < 3; i++)
            if (check[i])
            {
                element &next = vis[targets[i]];
                if (next.cnt == 0)
                {
                    next.time = nowtime + 1;
                    q.push(targets[i]);
                }
                if (next.time == nowtime + 1)
                    next.cnt += nowcnt;
            }
    }
    printf("%d\n%d", vis[K].time, vis[K].cnt);
    return 0;
}