#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator: if a+b > b+a, a should come first
int cmp(const void *p1, const void *p2) {
    char ab[40], ba[40];
    sprintf(ab, "%s%s", *(char **)p1, *(char **)p2);
    sprintf(ba, "%s%s", *(char **)p2, *(char **)p1);
    return strcmp(ba, ab); // descending
}

int main(void) {
    int n;
    scanf("%d", &n);

    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(20);
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char *), cmp);

    // Edge case: if first is "0"
    if (strcmp(arr[0], "0") == 0) {
        printf("0\n");
    } else {
        for (int i = 0; i < n; i++) printf("%s", arr[i]);
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return 0;
}
