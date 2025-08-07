#include <stdio.h>

int totalFruit(int* fruits, int fruitsSize) {
    int maxLen = 0, start = 0;
    int count[100001] = {0}; // assuming fruit types are <= 100000
    int types = 0;

    for (int end = 0; end < fruitsSize; end++) {
        if (count[fruits[end]] == 0) types++;
        count[fruits[end]]++;

        while (types > 2) {
            count[fruits[start]]--;
            if (count[fruits[start]] == 0) types--;
            start++;
        }

        int windowSize = end - start + 1;
        if (windowSize > maxLen) maxLen = windowSize;
    }

    return maxLen;
}

int main() {
    int fruits[] = {1, 2, 1};
    int size = sizeof(fruits) / sizeof(fruits[0]);
    printf("Max Fruits in Two Baskets: %d\n", totalFruit(fruits, size));
    return 0;
}

