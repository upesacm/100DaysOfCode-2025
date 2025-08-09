#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int sum;
    int freq;
} HashNode;

int findFreq(HashNode hash[], int size, int sum) {
    for (int i = 0; i < size; i++)
        if (hash[i].sum == sum) return hash[i].freq;
    return 0;
}

void updateFreq(HashNode hash[], int *size, int sum) {
    for (int i = 0; i < *size; i++) {
        if (hash[i].sum == sum) {
            hash[i].freq++;
            return;
        }
    }
    hash[*size].sum = sum;
    hash[*size].freq = 1;
    (*size)++;
}

int main() {
    int n, goal;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter binary array elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Enter goal: ");
    scanf("%d", &goal);

    HashNode hash[MAX];
    int hashSize = 0;
    updateFreq(hash, &hashSize, 0);

    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        count += findFreq(hash, hashSize, sum - goal);
        updateFreq(hash, &hashSize, sum);
    }

    printf("Number of subarrays: %d\n", count);
    return 0;
}
