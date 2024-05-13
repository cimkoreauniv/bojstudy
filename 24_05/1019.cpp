#include <stdio.h>
#include <string.h>

int pow10(int n) // 10 ** n
{
    int ret = 1;
    for (int i = 0; i < n; i++)
        ret *= 10;
    return ret;
}

char s[11];
int N[10];

int main(void)
{
    scanf("%s", &s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        N[i] = s[i] - '0';
    int cnt = 0;
    for (int j = 1; j < len; j++)
    {
        int a = 0;
        for (int k = 0; k < j; k++)
            a = a * 10 + N[k];
        int b = 0;
        for (int k = j + 1; k < len; k++)
            b = b * 10 + N[k];
        int l_b = len - j - 1;
        cnt += (a - 1) * pow10(l_b);
        if (N[j] == 0)
            cnt += b + 1;
        else if (N[j] > 0)
            cnt += pow10(l_b);
    }
    printf("%d ", cnt);
    for (int m = 1; m < 10; m++)
    {
        cnt = 0;
        for (int j = 0; j < len; j++)
        {
            int a = 0;
            for (int k = 0; k < j; k++)
                a = a * 10 + N[k];
            int b = 0;
            for (int k = j + 1; k < len; k++)
                b = b * 10 + N[k];
            int l_b = len - j - 1;
            cnt += a * pow10(l_b);
            if (N[j] == m)
                cnt += b + 1;
            else if (N[j] > m)
                cnt += pow10(l_b);
        }
        printf("%d ", cnt);
    }
    return 0;
}