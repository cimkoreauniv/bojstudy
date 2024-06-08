#include <stdio.h>
#include <memory.h>

int board[60][60];
int next[60][60];
int main(void)
{
    int R, C, T;
    int cond_row; // air conditioner upper row
    scanf("%d %d %d", &R, &C, &T);
    memset(board, -1, sizeof(board));
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == -1)
                cond_row = i;
        }
    cond_row--;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    for (int t = 0; t < T; t++)
    {
        memset(next, 0, sizeof(next));
        next[cond_row][1] = next[cond_row + 1][1] = -1;
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                if (board[i][j] > 0)
                {
                    int div5 = board[i][j] / 5;
                    for (int k = 0; k < 4; k++)
                        if (board[i + dy[k]][j + dx[k]] >= 0)
                            next[i + dy[k]][j + dx[k]] += div5, board[i][j] -= div5;
                    next[i][j] += board[i][j];
                }
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                if (next[i][j] >= 0)
                    board[i][j] = next[i][j];
        int k = 0;
        int nowx = 1, nowy = cond_row - 1;
        while (k < 4)
        {
            // printf("%d %d\n", nowx, nowy);
            if (k == 2 && nowy == cond_row)
                k++;
            else if (board[nowy + dy[k]][nowx + dx[k]] == -1)
                k++;
            else
            {
                board[nowy][nowx] = board[nowy + dy[k]][nowx + dx[k]];
                nowy += dy[k], nowx += dx[k];
            }
        }
        board[cond_row][2] = 0;

        k = 0;
        nowx = 1, nowy = cond_row + 2;
        while (k < 4)
        {
            if (k == 2 && nowy == cond_row + 1)
                k++;
            else if (board[nowy - dy[k]][nowx + dx[k]] == -1)
                k++;
            else
            {
                board[nowy][nowx] = board[nowy - dy[k]][nowx + dx[k]];
                nowy -= dy[k], nowx += dx[k];
            }
        }
        board[cond_row + 1][2] = 0;
        // printf("T: %d\n", t);
        // for (int i = 1; i <= R; i++)
        // {
        //     for (int j = 1; j <= C; j++)
        //         printf("%2d ", board[i][j]);
        //     printf("\n");
        // }
    }
    int ans = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            ans += board[i][j] > 0 ? board[i][j] : 0;
    printf("%d", ans);
    return 0;
}