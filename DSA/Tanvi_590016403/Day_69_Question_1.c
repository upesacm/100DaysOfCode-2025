#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// ---------- Problem 1: Palindrome Rearrangement ----------
bool canFormPalindrome(char str[]) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++)
        freq[(unsigned char)str[i]]++;

    int oddCount = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0)
            oddCount++;
    }
    return oddCount <= 1;  // At most one odd allowed
}

// ---------- Problem 2: Split Array into Equal Sum ----------
bool subsetSum(int arr[], int n, int sum) {
    bool dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

bool canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if (total % 2 != 0)
        return false;

    return subsetSum(arr, n, total/2);
}

// ---------- Problem 3: Longest Substring Without Repeating ----------
int longestUniqueSubstring(char str[]) {
    int n = strlen(str);
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;

    for (int end = 0; end < n; end++) {
        if (lastIndex[(unsigned char)str[end]] >= start) {
            start = lastIndex[(unsigned char)str[end]] + 1;
        }
        lastIndex[(unsigned char)str[end]] = end;
        int windowLen = end - start + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }
    return maxLen;
}

// ---------- Main Function ----------
int main() {
    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Check Palindrome Rearrangement\n");
        printf("2. Check Equal Sum Partition\n");
        printf("3. Longest Substring Without Repeating Characters\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char str[MAX];
            printf("Enter string: ");
            scanf("%s", str);
            if (canFormPalindrome(str))
                printf("Yes\n");
            else
                printf("No\n");

        } else if (choice == 2) {
            int n;
            printf("Enter array size: ");
            scanf("%d", &n);
            int arr[n];
            printf("Enter elements: ");
            for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
            if (canPartition(arr, n))
                printf("true\n");
            else
                printf("false\n");

        } else if (choice == 3) {
            char str[MAX];
            printf("Enter string: ");
            scanf("%s", str);
            printf("Length of longest substring without repeating characters: %d\n", longestUniqueSubstring(str));

        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
