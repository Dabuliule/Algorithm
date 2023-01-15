#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010, INF = 1e5;
int a[N];

void quickSort(int l, int r){
    if(l >= r) return;
    
    int i = l, x = a[l + r >> 1], p = l - 1, q = r + 1;
    while(i < q){
        while(i < q && a[i] > x) swap(a[i], a[--q]);
        while(i < q && a[i] == x) ++i;
        while(i < q && a[i] < x) swap(a[i++], a[++p]);
    }
    
    quickSort(l, p);
    quickSort(q, r);
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    
    quickSort(1, n);
    
    for(int i = 1; i <= n; ++i){
        printf("%d ", a[i]);
    }
    
    system("pause");
    return 0;
}