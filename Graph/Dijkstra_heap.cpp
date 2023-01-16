#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

// 最小堆优化版 Dijkstra 算法思想如下：
// 稀疏图很显然不能用邻接矩阵存储
// 首先空间上浪费
// 其次时间上寻找到源点距离最短的点的开销很大
// 并且以该点更新其余点到源点的最短距离的开销也很大
// 所以可以使用一个最小堆来维护被更新过，但是还未确定最短距离的点集
// 是以到每个点目前到源点的最短距离来建立最小堆

const int N = 150010;

typedef pair<int, int> pii;
bool vis[N];
vector<pii> g[N];
int d[N], m, n;

void add(int &a, int &b, int &c)
{
    g[a].push_back({b, c});
}

int dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> h;
    h.push({0, 1});
    while (!h.empty())
    {
        pii t = h.top();
        h.pop();
        int ver = t.second, dis = t.first;
        if (vis[ver])
            continue;
        vis[ver] = true;
        for (int i = 0; i < g[ver].size(); ++i)
        {
            int j = g[ver][i].first;
            if (d[j] > d[ver] + g[ver][i].second)
            {
                d[j] = d[ver] + g[ver][i].second;
                h.push({d[j], j});
            }
        }
    }
    return d[n] == 0x3f3f3f3f ? -1 : d[n];
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    cout << dijkstra();
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <cstring>
// #include <cstdio>
// using namespace std;

// const int N = 150010, INF = 0x3f3f3f3f;
// typedef pair<int, int> pii;
// struct Node
// {
//     int v, w;
// };
// vector<Node> g[N];
// int d[N];
// bool vit[N];

// int main()
// {
//     int m, n;
//     cin >> n >> m;

//     while (m--)
//     {
//         int a, b, w;
//         scanf("%d%d%d", &a, &b, &w);
//         g[a].push_back({b, w});
//     }

//     memset(d, 0x3f, sizeof(d));
//     priority_queue<pii, vector<pii>, greater<pii>> q;
//     d[1] = 0;
//     q.push({0, 1});
//     while (!q.empty())
//     {
//         pii t = q.top();
//         q.pop();
//         int dis = t.first, idx = t.second;
//         if (vit[idx])
//             continue;
//         vit[idx] = true;
//         for (int i = 0; i < g[idx].size(); ++i)
//         {
//             int v = g[idx][i].v, w = g[idx][i].w;
//             if (d[v] > d[idx] + w)
//             {
//                 d[v] = d[idx] + w;
//                 q.push({d[v], v});
//             }
//         }
//     }

//     if (d[n] == INF)
//         cout << -1 << endl;
//     else
//         cout << d[n] << endl;

//     return 0;
// }
