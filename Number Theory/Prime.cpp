// 埃氏筛法
// 同一个合数可能多次被标记

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;
bool vit[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i)
    {
        if (vit[i])
            continue;
        primes[cnt++] = i;
        for (int j = 2 * i; j <= n; j += i)
        {
            vit[j] = true;
        }
    }

    cout << cnt << endl;

    return 0;
}

// 欧拉筛法
// 每个合数都是被他最小的质因数筛掉

// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// bool vit[N];
// int primes[N];

// int main()
// {
//     int n;
//     cin >> n;

//     int cnt = 0;
//     for (int i = 2; i <= n; ++i)
//     {
//         if (!vit[i])
//             primes[cnt++] = i;
//         for (int j = 0; primes[j] <= n / i; ++j)
//         {
//             // 每次都要使用最小的质因数筛掉 i * primes[j]
//             vit[i * primes[j]] = true;
//             if (i % primes[j] == 0)
//                 // i % primes[j] == 0
//                 // 换言之，i 之前被 primes[j] 筛过了
//                 // 由于 primes 里面质数是从小到大的
//                 // 所以 i 乘上其他的质数的结果一定会被 primes[j] 的倍数筛掉
//                 // 就不需要在这里先筛一次，所以这里直接 break
//                 break;
//         }
//     }

//     cout << cnt << endl;

//     return 0;
// }