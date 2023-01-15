#include <cstdio>
#include <algorithm>

const int N = 1e5 + 10, M = 1e6 + 10;
int ne[N]; // ne[i] 代表如果第 i 位失配，模式串应该用第几位去跟主串的当前位置继续匹配
char s[M], p[N];

int main()
{
    int n, m;
    scanf("%d%s%d%s", &n, p + 1, &m, s + 1);

    for (int i = 1, j = 0; i <= n;)
    {
        if (j == 0 || p[i] == p[j])
            ne[++i] = ++j;
        else
            j = ne[j];
        if (p[ne[i]] == p[i])
            ne[i] = ne[ne[i]];
    }

    // for (int i = 1; i <= n; ++i)
    //     printf("%d ", ne[i]);

    // printf("\n");

    for (int i = 1, j = 1; i <= m; ++i)
    {
        while (j && s[i] != p[j])
            j = ne[j];
        if (++j == n + 1)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    system("pause");

    return 0;
}