#include <stdio.h>

int candy(int ratings[], int n) {
    int left[n], right[n];
    for (int i = 0; i < n; i++) left[i] = right[i] = 1;

    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;

    for (int i = n-2; i >= 0; i--)
        if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;

    int total = 0;
    for (int i = 0; i < n; i++)
        total += (left[i] > right[i] ? left[i] : right[i]);

    return total;
}

int main() {
    int arr1[] = {1, 0, 2};
    printf("Candies needed: %d\n", candy(arr1, 3)); // 5

    int arr2[] = {1, 2, 2};
    printf("Candies needed: %d\n", candy(arr2, 3)); // 4
    return 0;
}
