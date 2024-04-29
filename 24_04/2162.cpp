#include <stdio.h>
#include <algorithm>
using namespace std;

struct point
{
    int x, y;
};

bool operator<(point a, point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

struct line
{
    point p1, p2;
} lines[3010];

int ccw(point p1, point p2, point p3) // -: ccw, +: cw, 0: parallel
{
    int n = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    if (n < 0)
        return -1;
    else if (n > 0)
        return 1;
    return 0;
}

bool cross(line l1, line l2)
{
    int ab = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int cd = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
    if (ab == 0 && cd == 0)
        return !(max(l2.p1, l2.p2) < min(l1.p1, l1.p2) || max(l1.p1, l1.p2) < min(l2.p1, l2.p2));
    return ab <= 0 && cd <= 0;
}

struct node
{
    int parent, cnt;
} tree[3010];

int find(int n)
{
    if (tree[n].parent == n)
        return n;
    return tree[n].parent = find(tree[n].parent);
}

int main(void)
{
    int N;
    // printf("%d\n", cross({{1, 1}, {2, 2}}, {2, 2, 2, 3}));
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        point &p1 = lines[i].p1, &p2 = lines[i].p2;
        scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
    }
    for (int i = 0; i < N; i++)
        tree[i] = {i, 1};
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         printf("%d ", cross(lines[i], lines[j]));
    //     printf("\n");
    // }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            if (cross(lines[i], lines[j]))
            {
                int a = find(i), b = find(j);
                if (a != b)
                {
                    tree[b].parent = a;
                    tree[a].cnt += tree[b].cnt;
                }
            }
    }
    int cnt = 0, maxn = 0;
    for (int i = 0; i < N; i++)
    {
        if (tree[i].parent == i)
            cnt++;
        maxn = max(maxn, tree[i].cnt);
    }
    printf("%d\n%d", cnt, maxn);
    return 0;
}