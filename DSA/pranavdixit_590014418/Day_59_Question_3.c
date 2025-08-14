#include <stdio.h>

int areIdenticalHeaps(int arr1[], int arr2[], int n1, int n2) {
    if (n1 != n2) return 0;
    for (int i = 0; i < n1; i++)
        if (arr1[i] != arr2[i])
            return 0;
    return 1;
}

int main() {
    int arr1[] = {10, 9, 8};
    int arr2[] = {10, 9, 8};
    int arr3[] = {10, 8, 9};

    printf("%s\n", areIdenticalHeaps(arr1, arr2, 3, 3) ? "true" : "false"); // true
    printf("%s\n", areIdenticalHeaps(arr1, arr3, 3, 3) ? "true" : "false"); // false
    return 0;
}
