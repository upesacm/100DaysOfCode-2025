#include <stdio.h>

int isHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) return 0;   // Max-heap check
        if (right < n && arr[i] < arr[right]) return 0;
    }
    return 1;
}

int areHeapsIdentical(int arr1[], int n1, int arr2[], int n2) {
    if (n1 != n2) return 0;
    if (!isHeap(arr1, n1) || !isHeap(arr2, n2)) return 0;
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++) scanf("%d", &arr1[i]);

    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    if (areHeapsIdentical(arr1, n1, arr2, n2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
