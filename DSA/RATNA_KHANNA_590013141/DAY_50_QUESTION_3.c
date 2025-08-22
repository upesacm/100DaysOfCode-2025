#include <stdio.h>

int main() {
    int n, target;
     printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter target\n");
    scanf("%d", &target);

    int start = 0, sum = 0, found = 0;
    for(int end = 0; end < n; end++) {
        sum += arr[end];
        while(sum > target && start < end)
            sum -= arr[start++];

        if(sum == target) {
            printf("Subarray found from index %d to %d", start, end);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No subarray found");
    return 0;
}
