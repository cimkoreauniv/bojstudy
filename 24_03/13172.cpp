#include <stdio.h>

#define MOD 1000000007LL

typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    ll half = pow(a, b / 2);
    return half * half % MOD * (b % 2 ? a : 1) % MOD;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll g = gcd(a, b);
        a /= g, b /= g;
        ans = (ans + (b * pow(a, MOD - 2) % MOD)) % MOD;
    }
    printf("%lld", ans);
    return 0;
}