#include <stdio.h>

int b(int);

int a(int n) // 가장 왼쪽 줄이 세칸
{
    if (n == 2)
        return 3;
    if (n % 2 != 0)
        return 0;
    return b(n - 1) * 2 + a(n - 2);
}
int b(int n) // 가장 왼쪽 줄이 코너 두칸
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return 0;
    return a(n - 1) + b(n - 2);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%d", a(N));
    return 0;
}