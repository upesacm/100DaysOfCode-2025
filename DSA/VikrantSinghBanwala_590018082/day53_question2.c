#include <stdio.h>
#include <stdlib.h>

#define MAX_FRUIT_TYPE 100000

int totalFruit(int* fruits, int fruitsSize) {
    int count[MAX_FRUIT_TYPE] = {0};  
    int left = 0, right = 0;
    int maxLen = 0;
    int uniqueTypes = 0;

    while (right < fruitsSize) {
        if (count[fruits[right]] == 0) {
            uniqueTypes++;
        }
        count[fruits[right]]++;
        right++;

        while (uniqueTypes > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0) {
                uniqueTypes--;
            }
            left++;
        }

        if (right - left > maxLen) {
            maxLen = right - left;
        }
    }

    return maxLen;
}

int main() {
    
    int fruits1[] = {1, 2, 1};
    int size1 = sizeof(fruits1) / sizeof(fruits1[0]);
    printf("Max fruits collected (Example 1): %d\n", totalFruit(fruits1, size1));  // ➜ 3

    
    int fruits2[] = {0, 1, 2, 2};
    int size2 = sizeof(fruits2) / sizeof(fruits2[0]);
    printf("Max fruits collected (Example 2): %d\n", totalFruit(fruits2, size2));  // ➜ 3

    return 0;
}