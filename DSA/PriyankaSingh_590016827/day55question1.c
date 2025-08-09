#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int sum;
    int index;
} HashNode;

int findIndex(HashNode hash[], int size, int sum) {
    for (int i = 0; i < size; i++)
        if (hash[i].sum == sum) return hash[i].index;
    return -1;
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);

    HashNode hash[MAX];
    int hashSize = 0;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) maxLen = i + 1;

        int idx = findIndex(hash, hashSize, sum - k);
        if (idx != -1) {
            if (i - idx > maxLen) maxLen = i - idx;
        }

        if (findIndex(hash, hashSize, sum) == -1) {
            hash[hashSize].sum = sum;
            hash[hashSize].index = i;
            hashSize++;
        }
    }

    printf("Longest subarray length: %d\n", maxLen);
    return 0;
}
