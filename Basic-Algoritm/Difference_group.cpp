#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];

// 构造差分数组
// 差分数组的前缀和即为原数组
// 原数组的 [l, r] 的每个位置的元素都 + x
// 即差分数组的 l 位置元素 + x, r 位置元素 - x
void insert(int l, int r, int x)
{
    a[l] += x;
    a[r + 1] -= x;
}

int main()
{
    int n, m, l, r, x;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        insert(i, i, x);
    }

    while (m--)
    {
        cin >> l >> r >> x;
        insert(l, r, x);
    }

    for (int i = 1; i <= n; ++i)
    {
        a[i] += a[i - 1];
        cout << a[i] << " ";
    }

    cout << endl;
    system("pause");

    return 0;
}