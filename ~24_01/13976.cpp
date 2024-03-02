#include <stdio.h>
#define MOD 1000000007LL
typedef long long ll;
//[a00 a01]
//[a10 a11]
struct mat2x2
{
    ll a00, a01;
    ll a10, a11;
};

mat2x2 identity = {1, 0, 0, 1};
mat2x2 base = {4, -1, 1, 0};

mat2x2 matmul(mat2x2 a, mat2x2 b) // a*b
{
    mat2x2 ret;
    ret.a00 = (a.a00 * b.a00 % MOD + a.a01 * b.a10 % MOD) % MOD;
    ret.a01 = (a.a00 * b.a01 % MOD + a.a01 * b.a11 % MOD) % MOD;
    ret.a10 = (a.a10 * b.a00 % MOD + a.a11 * b.a10 % MOD) % MOD;
    ret.a11 = (a.a10 * b.a01 % MOD + a.a11 * b.a11 % MOD) % MOD;
    if (ret.a00 < 0)
        ret.a00 += MOD;
    if (ret.a01 < 0)
        ret.a01 += MOD;
    if (ret.a10 < 0)
        ret.a10 += MOD;
    if (ret.a11 < 0)
        ret.a11 += MOD;
    return ret;
}

mat2x2 matpow(long long n)
{
    if (n == 0LL)
        return identity;
    if (n == 1LL)
        return base;
    mat2x2 half = matpow(n / 2);
    mat2x2 ret = matmul(half, half);

    if (n % 2)
        ret = matmul(ret, base);
    return ret;
}

int main(void)
{
    long long n;
    mat2x2 m0 = {11, 3, 3, 1};
    scanf("%lld", &n);
    if (n % 2)
        printf("%d", 0);
    else
        printf("%lld", matmul(matpow(n / 2), m0).a11);
    return 0;
}