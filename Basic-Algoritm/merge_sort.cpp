#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int a[N], help[N];

void mergeSort(int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int p = 1, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) help[p++] = a[i++];
        else help[p++] = a[j++];
    }
    while(i <= mid) help[p++] = a[i++];
    while(j <= r) help[p++] = a[j++];
    
    for(int i = l, j = 1; i <= r; ++i, ++j){
        a[i] = help[j];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    
    mergeSort(1, n);
    
    for(int i = 1; i <= n; ++i){
        printf("%d ", a[i]);
    }
    
    printf("/n");

    system("pause");
    return 0;
}