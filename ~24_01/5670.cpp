// 5670
// Trie 응용

#include <stdio.h>
#include <memory.h>
#include <string.h>

struct Node
{
    int cnt;
    int next[27]; // 0~25: 'a'~'z', 26: end
} trie[1000010];
int trieLen;
int ans;

void dfs(int now, int pressed)
{
    if (trie[now].cnt == 0) // 종결 지점
    {
        ans += pressed;
        return;
    }
    for (int i = 0; i < 27; i++)
        if (trie[now].next[i] != -1)
        {
            // 종료 글자가 아니면서 갈래가 생기는 부분에서는 버튼을 눌러야 함
            int pressed_next = pressed + (i != 26 && trie[now].cnt > 1);
            dfs(trie[now].next[i], pressed_next);
        }
}

int main(void)
{
    int N;
    char str[90];
    while (scanf("%d", &N) != EOF)
    {
        trie[0].cnt = 0;
        memset(trie[0].next, -1, sizeof(trie[0].next));
        trieLen = 1;
        for (int i = 0; i < N; i++)
        {
            scanf("%s", str);
            int len = strlen(str);
            str[len] = 'z' + 1;
            str[len + 1] = 0;
            int now = 0;
            for (int j = 0; str[j]; j++)
            {
                if (trie[now].next[str[j] - 'a'] == -1)
                {
                    trie[now].cnt++;
                    trie[trieLen].cnt = 0;
                    memset(trie[trieLen].next, -1, sizeof(trie[trieLen].next));
                    trie[now].next[str[j] - 'a'] = trieLen++;
                }
                now = trie[now].next[str[j] - 'a'];
            }
        }
        ans = 0;
        dfs(0, trie[0].cnt == 1 /*첫 글자는 반드시 눌러져야 함*/);
        printf("%.2f\n", (double)ans / N);
    }
    return 0;
}