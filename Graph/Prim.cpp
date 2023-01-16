#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// prim 算法求最小生成树的思想如下：
// 用一个距离数组 d[] 记录未访问过的点到已访问过的点集（即已构建的生成树）的最小距离
// 从任意一个点开始访问
// 找出与当前生成树距离最小的点，并访问
// 更新其余访问过的点到已访问过的点集（即已构建的生成树）的最小距离
// 循环上述操作

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], d[N];
bool vit[N];

int main()
{
    int m, n;
    cin >> n >> m;

    memset(g, 0x3f, sizeof(g));
    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = g[b][a] = min(g[a][b], w);
    }

    int ans = 0;

    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; ++i)
    {

        int t = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!vit[j] && d[j] < d[t])
                t = j;
        }
        vit[t] = true;

        if (d[t] == INF)
        {
            ans = INF;
            break;
        }
        ans += d[t];

        for (int j = 1; j <= n; ++j)
            d[j] = min(d[j], g[t][j]);
    }

    if (ans == INF)
        puts("impossible");
    else
        cout << ans << endl;

    system("pause");
    return 0;
}