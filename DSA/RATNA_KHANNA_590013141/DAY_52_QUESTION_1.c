#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int hasPairWithSum(int arr[], int n, int x) {
    qsort(arr, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x)
            return 1;
        else if (sum < x)
            left++;
        else
            right--;
    }
    return 0;
}

int main() {
    int n, x;
    printf("enter number of array elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter value of x\n");
    scanf("%d", &x);
    if (hasPairWithSum(arr, n, x))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
