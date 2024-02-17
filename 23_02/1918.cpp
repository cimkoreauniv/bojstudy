#include <stdio.h>
#include <stack>

int priority(char c)
{
    switch (c)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 1;
    }
}

int main(void)
{
    char str[110];
    char ans[110];
    int len = 0;
    scanf("%s", str);
    std::stack<char> s;
    for (int i = 0; str[i]; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            ans[len++] = str[i];
        else if (str[i] == ')')
        {
            while (s.top() != '(')
            {
                ans[len++] = s.top();
                s.pop();
            }
            s.pop();
        }
        else if (str[i] == '(')
            s.push('(');
        else
        {
            while (!s.empty() && priority(str[i]) <= priority(s.top()))
            {
                ans[len++] = s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (!s.empty())
    {
        ans[len++] = s.top();
        s.pop();
    }
    ans[len] = 0;
    printf("%s", ans);
}