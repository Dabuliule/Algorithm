#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
char s1[N], s2[N];
int a[N], b[N], res[N];

int main()
{
    scanf("%s%s", s1, s2);
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
        if (cnt < n)
            t += a[cnt];
        if (cnt < m)
            t += b[cnt];
        res[cnt++] = t % 10;
        t /= 10;
    }

    while (t)
    {
        res[cnt++] = t % 10;
        t /= 10;
    }

    for (int i = cnt - 1; i >= 0; --i)
        printf("%d", res[i]);
    puts("");

    system("pause");
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> add(vector<int> &A, vector<int> &B)
// {
//     vector<int> C;

//     int t = 0;
//     for (int i = 0; i < A.size() || i < B.size(); ++i)
//     {
//         if (i < A.size())
//             t += A[i];
//         if (i < B.size())
//             t += B[i];
//         C.push_back(t % 10);
//         t /= 10;
//     }
//     if (t)
//         C.push_back(1);

//     return C;
// }

// int main()
// {
//     string a, b;
//     vector<int> A, B;

//     cin >> a >> b;
//     for (int i = a.size() - 1; i >= 0; --i)
//         A.push_back(a[i] - '0');
//     for (int i = b.size() - 1; i >= 0; --i)
//         B.push_back(b[i] - '0');

//     vector<int> C = add(A, B);

//     for (int i = C.size() - 1; i >= 0; --i)
//     {
//         printf("%d", C[i]);
//     }

//     return 0;
// }