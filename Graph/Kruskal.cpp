#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

// Kruskal 算法思想如下：
// 对边集从小到大排序
// 依次选择较小边
// 如果当前选择的边的两个顶点不在同一个生成树中，就选择该边，并把这两个顶点对应的生成树合并
// 合并操作使用并查集
// 如果当前选择的边的两个顶点在同一个生成树中，则跳过该边
// 循环上述操作
// 如果最后合并的次数为 n - 1 ，n为顶点数
// 则说明存在最小生成树

const int N = 100010, M = 200010;
struct Edge
{
    int a, b, w;
} edges[M];
int f[N];

int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

bool cmp(const Edge &x, const Edge &y)
{
    return x.w < y.w;
}

int main()
{
    int m, n;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    for (int i = 1; i <= n; ++i)
        f[i] = i;

    sort(edges, edges + m, cmp);
    int ans = 0, cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a == b)
            continue;

        f[a] = b;
        ans += w;
        cnt++;

        if (cnt == n - 1)
            break;
    }

    if (cnt < n - 1)
        puts("impossible");
    else
        cout << ans << endl;

    return 0;
}