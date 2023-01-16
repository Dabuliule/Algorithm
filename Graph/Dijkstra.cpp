#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Dijkstra 算法思想如下：
// 首先创建一个距离数组 dist[] 用于记录每个点到源点的最短距离
// dist[] 初始化为正无穷
// dist[源点] 初始化为 0
// 每次从未被确定到源点最短距离的点集中选择一个到源点距离最短的点
// 基于贪心的思想 由于边权都为正值 故该点到源点的最短距离确定
// 用该点去更新其余所有点（也可以只更新未被确定的点）到源点的最短距离
// 循环上述操作

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int m, n;

int dijkstra(int x)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[x] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int t = -1;
        for (int j = 1; j <= n; ++j)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
        for (int j = 1; j <= n; ++j)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra(1) << endl;
    return 0;
}