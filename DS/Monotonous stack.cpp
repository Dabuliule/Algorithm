#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int q[N], h = -1;

int main()
{
    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> x;

        while (h > -1 && q[h] >= x)
            h--;

        if (h == -1)
            cout << "-1 ";
        else
            cout << q[h] << " ";

        q[++h] = x;
    }

    system("pause");
    return 0;
}