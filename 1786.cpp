// 1786
// string search using KMP

#include <stdio.h>
#include <string.h>
#include <vector>
char T[1000010], P[1000010];
int lent, lenp;
int fail[1000010];

int main(void)
{
    fgets(T, sizeof(T), stdin);
    fgets(P, sizeof(P), stdin);
    lent = strlen(T) - 1;
    lenp = strlen(P) - 1;

    // Get Failure Function(FF)
    // Field of FF = max number of chars matched
    fail[0] = 0;

    int matched = 0, curidx = 1;
    while (curidx < lenp)
    {
        if (P[matched] == P[curidx])
            fail[curidx++] = ++matched;
        else if (matched == 0)
            fail[curidx++] = matched;
        else
            matched = fail[matched - 1];
    }

    std::vector<int> ans;
    matched = 0, curidx = 0;
    while (curidx < lent)
    {
        if (P[matched] == T[curidx])
        {
            matched++, curidx++;
            if (matched == lenp)
                ans.push_back(curidx - matched + 1);
        }
        else if (matched == 0)
            curidx++;
        else
            matched = fail[matched - 1];
    }
    printf("%d\n", ans.size());
    for (int idx : ans)
        printf("%d\n", idx);
    return 0;
}