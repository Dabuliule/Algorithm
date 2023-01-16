#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 由 AVO 网构造拓扑序列（不唯一）的思想如下：
// 用一个队列维护入度为 0 的所有点
// 每次出队都将出队的点输出，并且该点能直接到达的所有点的入度 -1
// 如果有新的点入度为 0 则入队
// 循环直至队列为空

const int N = 110;
int in[N];
vector<int> g[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int x;
        while (cin >> x, x)
        {
            g[i].push_back(x);
            in[x]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
            q.push(i);
    }

    while (q.size())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (--in[v] == 0)
                q.push(v);
        }
    }

    cout << endl;
    return 0;
}