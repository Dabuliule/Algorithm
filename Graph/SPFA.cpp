#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// SPFA 算法思想：
// 用一个栈或者队列维护被更新过最短距离的点的集合
// 每次出栈（队）一个点，并用该点去更新其他点到源点的最短距离
// 如果有点到源点的最短距离被更新，并且该点不在栈（队列）中
// 就把这个点入栈（队）
// 直至栈（队列）为空

const int N = 100010, INF = 0x3f3f3f3f;
struct Node
{
    int v, w;
};
vector<Node> g[N];
int d[N];
bool vit[N];

int main()
{
    int m, n;
    cin >> n >> m;

    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a].push_back({b, w});
    }

    queue<int> q;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    q.push(1);
    vit[1] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        vit[t] = false;
        for (int i = 0; i < g[t].size(); ++i)
        {
            int v = g[t][i].v, w = g[t][i].w;
            if (d[v] > d[t] + w)
            {
                d[v] = d[t] + w;
                if (!vit[v])
                {
                    q.push(v);
                    vit[v] = true;
                }
            }
        }
    }

    if (d[n] == INF)
        cout << "impossible" << endl;
    else
        cout << d[n] << endl;

    system("pause");
    return 0;
}