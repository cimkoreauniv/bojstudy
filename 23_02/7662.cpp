#include <stdio.h>
#include <set>

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        std::multiset<int> s;
        int k;
        scanf("%d", &k);
        char c;
        int n;
        while (k--)
        {
            scanf(" %c %d", &c, &n);
            if (c == 'I')
                s.insert(n);
            else if (s.empty())
                continue;
            else if (n == -1)
                s.erase(s.begin());
            else
                s.erase(--s.end());
        }
        if (s.empty())
            printf("EMPTY\n");
        else
            printf("%d %d\n", *(--s.end()), *s.begin());
    }
    return 0;
}