#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char ab[40], ba[40];
    sprintf(ab, "%s%s", *(char **)a, *(char **)b);
    sprintf(ba, "%s%s", *(char **)b, *(char **)a);
    return strcmp(ba, ab);
}

int main() {
    int n;
    scanf("%d", &n);
    char *arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(20);
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char *), compare);

    int allZero = 1;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], "0") != 0) {
            allZero = 0;
            break;
        }
    }

    if (allZero) {
        printf("0\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%s", arr[i]);
            free(arr[i]);
        }
        printf("\n");
    }

    return 0;
}
