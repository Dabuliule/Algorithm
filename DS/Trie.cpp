// https://www.acwing.com/problem/content/837/

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int son[N][26], cnt[N], idx = 0;
char str[N];

void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int j = str[i] - 'a';
        if (!son[p][j])
            son[p][j] = ++idx;
        p = son[p][j];
    }
    ++cnt[p];
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int j = str[i] - 'a';
        if (!son[p][j])
            return 0;
        p = son[p][j];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }

    system("pause");
    return 0;
}