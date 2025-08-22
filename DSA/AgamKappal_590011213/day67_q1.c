#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char ab[50], ba[50];
    strcpy(ab, *(char **)a);
    strcat(ab, *(char **)b);
    strcpy(ba, *(char **)b);
    strcat(ba, *(char **)a);
    return strcmp(ba, ab);
}

void largestNumber(int arr[], int n) {
    char *str[n];
    for (int i = 0; i < n; i++) {
        str[i] = (char *)malloc(20);
        sprintf(str[i], "%d", arr[i]);
    }

    qsort(str, n, sizeof(char *), compare);

    if (strcmp(str[0], "0") == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%s", str[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {10, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    largestNumber(arr1, n1);

    int arr2[] = {3, 30, 34, 5, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    largestNumber(arr2, n2);

    return 0;
}