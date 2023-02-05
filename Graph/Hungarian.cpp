// https://www.acwing.com/problem/content/863/

// Hungarian（匈牙利算法）思想：
// 从一个点开始依次经过未匹配边和匹配边，称为交替路
// 直到走到一个未匹配的点
// 这个时候经过的交替路中未匹配边比匹配边多一条
// 交换匹配边和未匹配边，总匹配边数加一

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 510;
vector<int> g[N];
int match[N];
bool vit[N];

bool find(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int j = g[x][i];

        if (vit[j])
            continue;

        vit[j] = true;
        if (match[j] == 0 || find(match[j]))
        {
            match[j] = x;
            return true;
        }
    }

    return false;
}

int main()
{
    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= n1; ++i)
    {
        memset(vit, false, sizeof(vit));
        if (find(i))
            ans++;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}