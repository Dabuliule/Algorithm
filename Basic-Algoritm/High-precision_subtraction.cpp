#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
char s1[N], s2[N];
int a[N], b[N], res[N];

int main()
{
    scanf("%s%s", s1, s2);

    bool flag = false;
    if (strlen(s1) < strlen(s2) || (strlen(s1) == strlen(s2) && strcmp(s1, s2) < 0))
    {
        swap(s1, s2);
        flag = true;
    }

    int n = strlen(s1), m = strlen(s2);
    for (int i = n - 1, j = m - 1, k = 0; i >= 0 || j >= 0; --i, --j, ++k)
    {
        if (i >= 0)
            a[k] = s1[i] - '0';
        if (j >= 0)
            b[k] = s2[j] - '0';
    }

    int t = 0, cnt = 0;
    while (cnt < n || cnt < m)
    {
        t += a[cnt];
        if (cnt < m)
            t -= b[cnt];
        res[cnt++] = (t + 10) % 10;
        t = (t - 9) / 10;
    }

    while (cnt > 1 && res[cnt - 1] == 0)
        cnt--;

    if (flag)
        printf("-");
    for (int i = cnt - 1; i >= 0; --i)
        printf("%d", res[i]);
    puts("");

    system("pause");
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// bool cmp(vector<int> &a, vector<int> &b)
// {
//     if (a.size() != b.size())
//         return a.size() > b.size();
//     for (int i = a.size() - 1; i >= 0; --i)
//     {
//         if (b[i] != a[i])
//             return a[i] > b[i];
//     }
//     return true;
// }

// vector<int> sub(vector<int> &a, vector<int> &b)
// {
//     vector<int> c;

//     int t = 0;
//     for (int i = 0; i < a.size(); ++i)
//     {
//         t = a[i] - t;
//         if (i < b.size())
//             t -= b[i];
//         c.push_back((t + 10) % 10);
//         if (t < 0)
//             t = 1;
//         else
//             t = 0;
//     }

//     while (c.size() > 1 && c.back() == 0)
//         c.pop_back();

//     return c;
// }

// int main()
// {
//     string s1, s2;
//     cin >> s1 >> s2;

//     vector<int> a, b;
//     for (int i = s1.size() - 1; i >= 0; --i)
//         a.push_back(s1[i] - '0');
//     for (int i = s2.size() - 1; i >= 0; --i)
//         b.push_back(s2[i] - '0');

//     vector<int> c;
//     if (cmp(a, b))
//     {
//         c = sub(a, b);
//     }
//     else
//     {
//         c = sub(b, a);
//         printf("-");
//     }

//     for (int i = c.size() - 1; i >= 0; --i)
//     {
//         printf("%d", c[i]);
//     }

//     return 0;
// }