#include <stdio.h>
#include <algorithm>

typedef long long ll;

struct Point
{
    int x, y;
} points[100010], minp;

int s[100010], len;

//+: ccw, -: cw, 0: line
ll ccw(Point a, Point b, Point c)
{
    return (ll)(b.x - a.x) * (c.y - b.y) - (ll)(b.y - a.y) * (c.x - b.x);
}

bool comp(Point a, Point b)
{
    if (ccw(minp, a, b) != 0)
        return ccw(minp, a, b) > 0;
    else if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    int minidx = 0;
    for (int i = 1; i < N; i++)
        if (points[minidx].y > points[i].y || (points[minidx].y == points[i].y && points[minidx].x > points[i].x))
            minidx = i;
    minp = points[minidx];
    points[minidx] = points[0];
    points[0] = minp;
    std::sort(points + 1, points + N, comp);
    s[0] = 0, s[1] = 1, len = 2;
    for (int i = 2; i < N; i++)
    {
        while (len > 1 && ccw(points[s[len - 2]], points[s[len - 1]], points[i]) <= 0)
            len--;
        s[len++] = i;
    }
    printf("%d", len);
    return 0;
}