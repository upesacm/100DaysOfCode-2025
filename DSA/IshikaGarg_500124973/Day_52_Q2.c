#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000 // Size for hash map (can be increased if needed)

// Simple hash set using boolean array
bool hash[MAX] = { false };

// Function to find all pairs with given difference k
void findPairsWithDifference(int arr[], int n, int k) {
    // Insert elements into the hash set
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < MAX)
            hash[arr[i]] = true;
    }

    printf("Pairs with difference %d:\n", k);
    for (int i = 0; i < n; i++) {
        int a = arr[i];

        // Check for (a, a + k)
        if ((a + k) >= 0 && (a + k) < MAX && hash[a + k])
            printf("(%d, %d)\n", a, a + k);

        // Optional: If you also want (a, a - k)
        if ((a - k) >= 0 && (a - k) < MAX && hash[a - k])
            printf("(%d, %d)\n", a, a - k);
    }
}
int main() {
    int arr1[] = {1, 5, 3, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;

    findPairsWithDifference(arr1, n1, k1);
    
    printf("\n");

    int arr2[] = {8, 12, 16, 4, 0, 20};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 4;

    findPairsWithDifference(arr2, n2, k2);

    return 0;
}

