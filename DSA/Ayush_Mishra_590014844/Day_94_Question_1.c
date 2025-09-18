#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], dp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) dp[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

    int max = dp[0];
    for (int i = 1; i < n; i++)
        if (dp[i] > max) max = dp[i];

    printf("%d\n", max);
    return 0;
}
