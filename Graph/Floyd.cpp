#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;

// 多源最短路 Floyd 算法思想：
// 用一个二维数组 d[][] 记录任意两点的最短距离
// 以每个点作为中间点
// 如以 k 为中间点
// 如果 i 到 j 的距离大于先从 i 到 k 再从 k 到 j 的距离
// 那么则用 d[i][k] + d[k][j] 去更新 d[i][j]

// 假设最外层循环已经经过 k 轮
// 那么 d[i][j] 的含义为：
// i 到 j 中间点可以有 1、2、3 ... k 的最短距离

const int N = 210, INF = 0x3f3f3f3f;
int n, m, q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (d[a][b] > INF / 2)
            puts("impossible");
        else
            printf("%d\n", d[a][b]);
    }

    system("pause");
    return 0;
}