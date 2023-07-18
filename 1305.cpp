// 1305
// application of KMP failure function

#include <stdio.h>
#include <string.h>
#include <vector>

int L;
char P[1000010];
int lent, lenp;
int fail[1000010];

int main(void)
{
    scanf("%d", &L);
    scanf("%s", P);
    lenp = strlen(P);

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
    printf("%d", L - fail[L - 1]);
    return 0;
}