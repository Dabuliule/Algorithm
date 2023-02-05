// https://www.acwing.com/problem/content/838/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int f[N];

int find(int x)
{
    return f[x] == x ? f[x] : find(f[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M')
            f[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    system("pause");
    return 0;
}