#include <stdio.h>

int func(int a[], int n) {
    int x = 0;
    for (int i = 0; i < n; i++) x ^= a[i];
    return x;
}

int main() {
    int a[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d\n", func(a, n));
    return 0;
}
