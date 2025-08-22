#include <stdio.h>

int totalFruit(int* fruits, int fruitsSize) {
    int count[100005] = {0};
    int left = 0, maxLen = 0, types = 0;

    for (int right = 0; right < fruitsSize; right++) {
        if (count[fruits[right]] == 0)
            types++;
        count[fruits[right]]++;

        while (types > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0)
                types--;
            left++;
        }

        int len = right - left + 1;
        if (len > maxLen) maxLen = len;
    }

    return maxLen;
}
