#include <stdio.h>

int main() {
    int n, x, i = 0, j = 0, sum = 0, minLen = 100001;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for (int k = 0; k < n; k++)
        scanf("%d", &arr[k]);
    printf("enter value of x\n");
    scanf("%d", &x);
    while (j < n) {
        sum += arr[j];
        while (sum > x) {
            if (j - i + 1 < minLen)
                minLen = j - i + 1;
            sum -= arr[i];
            i++;
        }
        j++;
    }
    if (minLen == 100001)
        printf("0\n");
    else
        printf("%d\n", minLen);
    return 0;
}
