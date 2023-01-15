#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000010;
int a[N], q[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    // 双端队列存的是严格单调递增的 a 的子序列的下标
    // 先弹出，再加入
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i)
    {
        // 如果队头存的下标小于当前窗口的最小下标，那么弹出队头
        if (i - k + 1 > q[hh])
            ++hh;

        // 如果a[队尾存的下标] >= a[i] ，那么弹出队尾，可以弹空
        while (hh <= tt && a[q[tt]] >= a[i])
            --tt;
        q[++tt] = i;
        // 此时队列一定不空

        if (i + 1 >= k)
            printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i)
    {
        if (i - k + 1 > q[hh])
            ++hh;

        while (hh <= tt && a[q[tt]] <= a[i])
            --tt;
        q[++tt] = i;

        if (i + 1 >= k)
            printf("%d ", a[q[hh]]);
    }

    puts("");

    system("pause");
    return 0;
}