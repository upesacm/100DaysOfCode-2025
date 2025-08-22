#include <stdio.h>

#define MAX 1000

typedef struct {
    int sum;
    int freq;
} Entry;

int getFreq(Entry* map, int size, int sum) {
    for (int i = 0; i < size; i++)
        if (map[i].sum == sum)
            return map[i].freq;
    return 0;
}

void addFreq(Entry* map, int* size, int sum, int value) {
    for (int i = 0; i < *size; i++) {
        if (map[i].sum == sum) {
            map[i].freq += value;
            return;
        }
    }
    map[*size].sum = sum;
    map[*size].freq = value;
    (*size)++;
}

int numSubarraysWithSum(int nums[], int n, int goal) {
    Entry map[MAX];
    int size = 0;
    int sum = 0, count = 0;

    addFreq(map, &size, 0, 1); // Base case

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        count += getFreq(map, size, sum - goal);
        addFreq(map, &size, sum, 1);
    }

    return count;
}

int main() {
    int nums[] = {1, 0, 1, 0, 1};
    int goal = 2;
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Number of subarrays: %d\n", numSubarraysWithSum(nums, n, goal)); // Output: 4
    return 0;
}
