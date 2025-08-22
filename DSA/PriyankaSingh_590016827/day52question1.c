#include <stdio.h>
#include <stdbool.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool hasPairWithSum(int arr[], int n, int x) {
    sort(arr, n);
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x)
            return true;
        else if (sum < x)
            left++;
        else
            right--;
    }
    return false;
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted or unsorted order:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &x);

    if (hasPairWithSum(arr, n, x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
