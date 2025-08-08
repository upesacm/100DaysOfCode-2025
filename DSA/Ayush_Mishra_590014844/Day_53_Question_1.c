#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxCount = 0, currentCount = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1)
            currentCount++;
        else
            currentCount = 0;
        if(currentCount > maxCount)
            maxCount = currentCount;
    }

    printf("%d\n", maxCount);
    return 0;
}
