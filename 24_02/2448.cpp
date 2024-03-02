#include <stdio.h>
#include <memory.h>
char grid[3072][6144];

void draw(int n, int x, int y)
{
    if (n == 3)
    {
        grid[y][x + 2] = '*';
        grid[y + 1][x + 1] = grid[y + 1][x + 3] = '*';
        for (int i = 0; i < 5; i++)
            grid[y + 2][x + i] = '*';
    }
    else
    {
        draw(n / 2, x + n / 2, y);
        draw(n / 2, x, y + n / 2);
        draw(n / 2, x + n, y + n / 2);
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    memset(grid, ' ', sizeof(grid));
    draw(N, 0, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }
    return 0;
}