// https://www.acwing.com/problem/content/150/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }

    printf("%d\n", ans);

    system("pause");
    return 0;
}