// https://www.acwing.com/problem/content/862/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int color[N];

bool dfs(int a, int c)
{
    color[a] = c;

    for (int i = 0; i < g[a].size(); ++i)
    {
        int b = g[a][i];
        if (!color[b])
        {
            if (!dfs(b, 3 - c))
                return false;
        }
        else if (color[b] == c)
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool flag = true;

    for (int i = 1; i <= n; ++i)
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
                flag = false;
        }
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    system("pause");
    return 0;
}