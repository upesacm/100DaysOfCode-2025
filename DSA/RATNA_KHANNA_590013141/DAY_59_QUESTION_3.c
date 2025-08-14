#include <stdio.h>
#include <stdlib.h>

int isMaxHeap(int *arr, int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[i] < arr[l]) return 0;
        if (r < n && arr[i] < arr[r]) return 0;
    }
    return 1;
}

int areIdenticalHeaps(int *a, int *b, int n1, int n2) {
    if (n1 != n2) return 0;
    if (!isMaxHeap(a, n1) || !isMaxHeap(b, n2)) return 0;
    for (int i = 0; i < n1; i++) if (a[i] != b[i]) return 0;
    return 1;
}

int main() {
    int n1, n2;
    printf("enter number of elements in  array1\n");
    if (scanf("%d", &n1) != 1) return 0;
    int *a = (int*)malloc(n1 * sizeof(int));
     printf("enter elements in  array1\n");
    for (int i = 0; i < n1; i++) scanf("%d", &a[i]);
    printf("enter number of elements in  array2\n");
    if (scanf("%d", &n2) != 1) { free(a); return 0; }
    int *b = (int*)malloc(n2 * sizeof(int));
     printf("enter elements in  array2\n");
    for (int i = 0; i < n2; i++) scanf("%d", &b[i]);
    printf(areIdenticalHeaps(a, b, n1, n2) ? "true\n" : "false\n");
    free(a);
    free(b);
    return 0;
}
