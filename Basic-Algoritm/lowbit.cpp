#include <iostream>
#include <algorithm>
using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x, res = 0;
        cin >> x;
        for (int i = x; i; i -= lowbit(i))
            res++;
        cout << res << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}