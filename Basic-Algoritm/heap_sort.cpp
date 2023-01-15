#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int h[N], n;

// 以下以小根堆为例
// 即根节点的值小于等于孩子节点的值

void down(int i)
{
    int t = i;
    if (2 * i <= n && h[2 * i] < h[t])
        t = 2 * i;
    if (2 * i + 1 <= n && h[2 * i + 1] < h[t])
        t = 2 * i + 1;
    if (t != i)
    {
        swap(h[t], h[i]);
        down(t);
    }
}

void up(int i)
{
    if (i > 0 && h[i >> 1] > h[i])
    {
        swap(h[i], h[i >> 1]);
        up(i >> 1);
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &h[i]);
        up(i);
    }

    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[n--];
        down(1);
    }
    puts("");

    system("pause");
    return 0;
}