#include <stdio.h>
#include <queue>

typedef std::pair<int, int> pos;

int board[22][22];

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < 22; i++)
        for (int j = 0; j < 22; j++)
            board[i][j] = 10000;
    int size = 2, left = 2;
    pos now;
    std::queue<pos> q;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9)
                board[i][j] = 0, now = {i, j};
        }
}