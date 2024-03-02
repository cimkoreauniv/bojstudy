#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int minans[2][3], maxans[2][3], now = 0;
int main(void)
{
    int N;
    int a, b, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        minans[!now][0] = min(minans[now][0], minans[now][1]) + a;
        minans[!now][1] = min(min(minans[now][0], minans[now][1]), minans[now][2]) + b;
        minans[!now][2] = min(minans[now][1], minans[now][2]) + c;
        maxans[!now][0] = max(maxans[now][0], maxans[now][1]) + a;
        maxans[!now][1] = max(max(maxans[now][0], maxans[now][1]), maxans[now][2]) + b;
        maxans[!now][2] = max(maxans[now][1], maxans[now][2]) + c;
        now = !now;
    }
    printf("%d ", max(maxans[now][0], max(maxans[now][1], maxans[now][2])));
    printf("%d", min(minans[now][0], min(minans[now][1], minans[now][2])));
    return 0;
}