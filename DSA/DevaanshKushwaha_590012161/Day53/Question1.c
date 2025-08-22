#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter binary array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int maxCount = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            if (count > maxCount) maxCount = count;
        } else count = 0;
    }
    printf("Maximum consecutive ones: %d", maxCount);
}
