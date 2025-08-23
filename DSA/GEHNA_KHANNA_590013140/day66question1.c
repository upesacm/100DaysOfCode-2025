#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    int *dep = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) scanf("%d", &dep[i]);

    qsort(arr, n, sizeof(int), cmp);
    qsort(dep, n, sizeof(int), cmp);

    int i = 0, j = 0, cur = 0, ans = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {      
            cur++;
            if (cur > ans) ans = cur;
            i++;
        } else {                     
            cur--;
            j++;
        }
    }
    printf("%d\n", ans);

    free(arr); free(dep);
    return 0;
}
