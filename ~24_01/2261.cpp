// BOJ 2261 Closest pair algorithm

#include <stdio.h>
#include <algorithm>

struct point
{
    int x, y;
} points[100010];

int sq(int x) { return x * x; }

int distsq(point a, point b)
{
    return sq(a.x - b.x) + sq(a.y - b.y);
}

point candidates[100010];

bool cmpx(point a, point b)
{
    return a.x < b.x;
}

bool cmpy(point a, point b)
{
    return a.y < b.y;
}

int mindist(int left, int right)
{
    if (right - left == 1) // 2 points
        return distsq(points[left], points[right]);
    else if (right - left == 2) // 3 points
        return std::min(
            std::min(distsq(points[left], points[left + 1]),
                     distsq(points[left], points[left + 2])),
            distsq(points[left + 1], points[left + 2]));
    int m = (left + right) / 2;
    int d = std::min(mindist(left, m), mindist(m + 1, right));
    int count = 0;
    for (int i = m - 1; i >= left && sq(points[m].x - points[i].x) < d; i--)
        candidates[count++] = points[i];
    for (int i = m; i <= right && sq(points[m].x - points[i].x) < d; i++)
        candidates[count++] = points[i];
    std::sort(candidates, candidates + count, cmpy);
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count && sq(candidates[i].y - candidates[j].y) < d; j++)
            d = std::min(d, distsq(candidates[i], candidates[j]));
    return d;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    std::sort(points, points + N, cmpx);
    printf("%d", mindist(0, N - 1));
}