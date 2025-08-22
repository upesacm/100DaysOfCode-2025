#include <stdio.h>
#include <stdlib.h>

int longest_Mountain(int arr[], int n) {
    if (n < 3) {
        return 0;
    }
    
    int maxLength = 0;
    int i = 1;
    
    while (i < n) {
        if (i < n - 1 && arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }
            
            int right = i + 1;
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }
            
            int currentLength = right - left + 1;
            if (currentLength >= 3 && currentLength > maxLength) {
                maxLength = currentLength;
            }
            
            i = right;
        } else {
            i++;
        }
    }
    
    return maxLength;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the elements of the array (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = longest_Mountain(arr, n);
    printf("Length of the longest mountain: %d\n", result);
    
    free(arr);
    return 0;
}
