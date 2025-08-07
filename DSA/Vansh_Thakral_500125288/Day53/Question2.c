#include <stdio.h>

#define MAX 100005

int totalFruit(int* fruits, int n) {
    int count[MAX] = {0};
    int left = 0, right = 0, maxLen = 0, typeCount = 0;

    while (right < n) {
        if (count[fruits[right]] == 0)
            typeCount++;
        count[fruits[right]]++;

        while (typeCount > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0)
                typeCount--;
            left++;
        }

        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;

        right++;
    }

    return maxLen;
}

int main() {
    int fruits[] = {0, 1, 2, 2};
    int n = sizeof(fruits) / sizeof(fruits[0]);

    printf("%d\n", totalFruit(fruits, n)); 
    return 0;
}

