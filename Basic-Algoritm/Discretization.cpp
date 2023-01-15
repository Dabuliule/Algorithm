#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//差分+前缀和
const int N = 3e5 + 10;
int a[N], s[N];

typedef pair<int, int> PII;

// 用来储存所有加过的位置，可能会有重复，因此需要排序然后去重
vector<int> alls;

// 用来储存每个加过的位置和加的数，以及询问的区间
vector<PII> add, query;

// 映射下标, x 是一定存在于 alls 中的，所以直接寻找 alls[?] == x
int find(int x)
{
    int l = -1, r = alls.size();
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r + 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //映射+初始化
    for (int i = 0; i < add.size(); ++i)
    {
        int x = find(add[i].first);
        a[x] += add[i].second;
    }

    //求前缀和
    for (int i = 1; i <= alls.size(); ++i)
    {
        s[i] = s[i - 1] + a[i];
    }

    //两种遍历方式
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    system("pause");
    return 0;
}