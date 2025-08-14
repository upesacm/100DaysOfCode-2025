#include <stdio.h>
#include <stdbool.h>

bool areHeapsIdentical(int arr1[], int arr2[], int n1, int n2) {
    if (n1 != n2) return false;
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main() {
    int arr1[] = {10, 9, 8};
    int arr2[] = {10, 9, 8};
    int arr3[] = {10, 8, 9};

    printf("%s\n", areHeapsIdentical(arr1, arr2, 3, 3) ? "true" : "false");
    printf("%s\n", areHeapsIdentical(arr1, arr3, 3, 3) ? "true" : "false");
    return 0;
}
