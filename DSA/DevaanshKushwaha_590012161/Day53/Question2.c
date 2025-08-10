#include <stdio.h>
int main() {
    int n;
    printf("Enter number of fruits: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter fruit types: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int count[100000] = {0}, left = 0, maxLen = 0, distinct = 0;
    for (int right = 0; right < n; right++) {
        if (count[arr[right]] == 0) distinct++;
        count[arr[right]]++;
        while (distinct > 2) {
            count[arr[left]]--;
            if (count[arr[left]] == 0) distinct--;
            left++;
        }
        if (right - left + 1 > maxLen) maxLen = right - left + 1;
    }
    printf("Maximum number of fruits: %d", maxLen);
}
