#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N][N], d[N][N];
int m, n, q;

void insert(int x1, int y1, int x2, int y2, int c)
{
    d[x1][y1] += c;
    d[x2 + 1][y1] -= c;
    d[x1][y2 + 1] -= c;
    d[x2 + 1][y2 + 1] += c;
}

int main()
{
    cin >> m >> n >> q;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);
        }
    }

    int x1, y1, x2, y2, c;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");

    return 0;
}