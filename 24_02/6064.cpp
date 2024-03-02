#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int M, N, x, y;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        x--, y--;
        for (int i = 0; i < N; i++)
        {
            int year = M * i + x;
            if (year % N == y)
            {
                printf("%d\n", year + 1);
                break;
            }
            if (i == N - 1)
                printf("-1\n");
        }
    }
}