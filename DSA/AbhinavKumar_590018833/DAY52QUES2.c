#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


void findPairsWithDiff(int arr[], int n, int k) {
    if (n < 2) return;

    
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = 1;
    int found = 0;

    printf("Output: [");
    while (right < n) {
        int diff = arr[right] - arr[left];

        if (diff == k) {
            if (found > 0) printf(", ");
            printf("(%d, %d)", arr[left], arr[right]);
            found++;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else { 
            left++;
        }
        if (left == right) {
            right++;
        }
    }
    printf("]\n");
}

int main_pairs() {
    int arr1[] = {1, 5, 3, 4, 2};
    int k1 = 2;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Input: arr = {1, 5, 3, 4, 2}, k = %d\n", k1);
    findPairsWithDiff(arr1, n1, k1);
    printf("\n");

    int arr2[] = {8, 12, 16, 4, 0, 20};
    int k2 = 4;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Input: arr = {8, 12, 16, 4, 0, 20}, k = %d\n", k2);
    findPairsWithDiff(arr2, n2, k2);
    
    return 0;
}