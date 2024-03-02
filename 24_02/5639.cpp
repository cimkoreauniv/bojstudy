#include <stdio.h>

struct node
{
    int data;
    node *l, *r;
};
node nodes[10010];
int len;

node *root;

void postorder(node *now)
{
    if (!now)
        return;
    postorder(now->l);
    postorder(now->r);
    printf("%d\n", now->data);
}

int main(void)
{
    while (true)
    {
        int n;
        if (scanf("%d", &n) != 1)
            break;
        node *newNode = &nodes[len++];
        newNode->data = n;
        if (!root)
        {
            root = newNode;
            continue;
        }
        node *now = root;
        while (true)
        {
            if (now->data > newNode->data)
            {
                if (now->l == NULL)
                {
                    now->l = newNode;
                    break;
                }
                else
                    now = now->l;
            }
            else
            {
                if (now->r == NULL)
                {
                    now->r = newNode;
                    break;
                }
                else
                    now = now->r;
            }
        }
    }
    postorder(root);
    return 0;
}