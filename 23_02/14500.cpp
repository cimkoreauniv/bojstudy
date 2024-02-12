#include <stdio.h>

int N, M;
int arr[510][510];

int max(int a, int b)
{
    return a > b ? a : b;
}

int get_I(int x, int y)
{
    int ret = 0;
    ret = max(ret, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3]);
    ret = max(ret, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x]);
    return ret;
}

int get_sq(int x, int y)
{
    return arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 1][x + 1];
}

int get_L(int x, int y)
{
    int grid[8][3][3] = {
        //
        {{1, 0, 0},
         {1, 0, 0},
         {1, 1, 0}},
        //
        {{1, 1, 1},
         {1, 0, 0},
         {0, 0, 0}},
        //
        {{1, 1, 0},
         {0, 1, 0},
         {0, 1, 0}},
        //
        {{0, 0, 1},
         {1, 1, 1},
         {0, 0, 0}},
        //
        {{1, 1, 0},
         {1, 0, 0},
         {1, 0, 0}},
        //
        {{1, 1, 1},
         {0, 0, 1},
         {0, 0, 0}},
        //
        {{0, 1, 0},
         {0, 1, 0},
         {1, 1, 0}},
        //
        {{1, 0, 0},
         {1, 1, 1},
         {0, 0, 0}}};
    int ret = 0;
    for (int i = 0; i < 8; i++)
    {
        int sum = 0;
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                sum += grid[i][a][b] * arr[y + a][x + b];
        ret = max(ret, sum);
    }
    return ret;
}

int get_S(int x, int y)
{
    int grid[4][3][3] = {
        //
        {{1, 0, 0},
         {1, 1, 0},
         {0, 1, 0}},
        //
        {{0, 1, 1},
         {1, 1, 0},
         {0, 0, 0}},
        //
        {{0, 1, 0},
         {1, 1, 0},
         {1, 0, 0}},
        //
        {{1, 1, 0},
         {0, 1, 1},
         {0, 0, 0}},
        //
    };
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                sum += grid[i][a][b] * arr[y + a][x + b];
        ret = max(ret, sum);
    }
    return ret;
}

int get_T(int x, int y)
{
    int grid[8][3][3] = {
        //
        {{1, 0, 0},
         {1, 1, 0},
         {1, 0, 0}},
        //
        {{1, 1, 1},
         {0, 1, 0},
         {0, 0, 0}},
        //
        {{0, 1, 0},
         {1, 1, 0},
         {0, 1, 0}},
        //
        {{0, 1, 0},
         {1, 1, 1},
         {0, 0, 0}},
        //
    };
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                sum += grid[i][a][b] * arr[y + a][x + b];
        ret = max(ret, sum);
    }
    return ret;
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            ans = max(ans, get_I(j, i));
            ans = max(ans, get_sq(j, i));
            ans = max(ans, get_L(j, i));
            ans = max(ans, get_S(j, i));
            ans = max(ans, get_T(j, i));
        }
    printf("%d", ans);
    return 0;
}