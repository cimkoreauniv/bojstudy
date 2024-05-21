#include <stdio.h>
#include <memory.h>
#include <vector>

int board[20][20];

int H[20][20], V[20][20], D[20][20];

int horizontal(int, int);
int vertical(int, int);
int diagonal(int, int);

int horizontal(int x, int y)
{
    if (H[y][x] != -1)
        return H[y][x];
    if (board[y][x] || board[y][x + 1])
        return 0;
    if (x == 1 && y == 1)
        return 1;
    return horizontal(x - 1, y) + diagonal(x - 1, y - 1);
}

int vertical(int x, int y)
{
    if (V[y][x] != -1)
        return V[y][x];
    if (board[y][x] || board[y + 1][x])
        return 0;
    return vertical(x, y - 1) + diagonal(x - 1, y - 1);
}

int diagonal(int x, int y)
{
    if (D[y][x] != -1)
        return D[y][x];
    if (board[y][x] || board[y + 1][x] || board[y][x + 1] || board[y + 1][x + 1])
        return 0;
    return diagonal(x - 1, y - 1) + horizontal(x - 1, y) + vertical(x, y - 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            board[i][j] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &board[i][j]);
    memset(H, -1, sizeof(H));
    memset(V, -1, sizeof(V));
    memset(D, -1, sizeof(D));
    printf("%d", horizontal(N - 1, N) + vertical(N, N - 1) + diagonal(N - 1, N - 1));
    return 0;
}