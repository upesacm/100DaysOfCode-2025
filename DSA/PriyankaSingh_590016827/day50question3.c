#include <stdio.h>

int main() {
    int arr[100], n, target, i, start = 0, sum = 0, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    for(i = 0; i < n; i++) {
        sum += arr[i];

        while(sum > target && start < i)
            sum -= arr[start++];

        if(sum == target) {
            printf("Subarray found from index %d to %d\n", start, i);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No subarray with given sum found.\n");

    return 0;
}
