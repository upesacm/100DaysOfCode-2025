#include <stdio.h>
#include <stdlib.h>

int fruit_in_basket(int fruits[], int n) {
    if (n == 0) {
        return 0;
    }

    int max_fruit = fruits[0];
    for (int i = 1; i < n; i++) {
        if (fruits[i] > max_fruit) {
            max_fruit = fruits[i];
        }
    }

    int *freq = (int *)calloc(max_fruit + 1, sizeof(int));
    if (freq == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    int uniqueCount = 0;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        if (freq[fruits[end]] == 0) {
            uniqueCount++;
        }
        freq[fruits[end]]++;

        while (uniqueCount > 2 && start <= end) {
            freq[fruits[start]]--;
            if (freq[fruits[start]] == 0) {
                uniqueCount--;
            }
            start++;
        }

        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    free(freq);
    return maxLength;
}

int main() {
    int n;
    printf("Enter the number of fruits: ");
    scanf("%d", &n);

    int *fruits = (int *)malloc(n * sizeof(int));
    if (fruits == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the types of fruits (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &fruits[i]);
    }

    int result = fruit_in_basket(fruits, n);
    if (result != -1) {
        printf("Maximum number of fruits you can pick: %d\n", result);
    }

    free(fruits);
    return 0;
}
