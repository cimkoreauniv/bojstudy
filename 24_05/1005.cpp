#include <stdio.h>
#include <vector>
#include <queue>
int D[1010];
std::vector<int> next[1010];
int left[1010]; // 짓기 위해 지어야 하는 건물의 개수

struct node
{
    int num, endtime;
};

bool operator<(node a, node b)
{
    return a.endtime > b.endtime;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, K, W;
        scanf("%d %d", &N, &K);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &D[i]);
            next[i].clear();
            left[i] = 0;
        }
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            scanf("%d %d", &X, &Y);
            next[X].push_back(Y);
            left[Y]++;
        }
        scanf("%d", &W);
        std::priority_queue<node> pq;
        int nowtime = 0;
        for (int i = 1; i <= N; i++)
            if (left[i] == 0)
                pq.push({i, nowtime + D[i]});
        while (!pq.empty())
        {
            int b = pq.top().num;
            nowtime = pq.top().endtime;
            pq.pop();
            if (b == W)
                break;
            for (int i : next[b])
            {
                left[i]--;
                if (left[i] == 0)
                    pq.push({i, nowtime + D[i]});
            }
        }
        printf("%d\n", nowtime);
    }
    return 0;
}