#include <stdio.h>
#include <stdlib.h>

int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;
    
    int jumps = 1;
    int current_max = arr[0];
    int farthest = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;
        
        farthest = (i + arr[i] > farthest) ? i + arr[i] : farthest;
        
        if (i == current_max) {
            jumps++;
            current_max = farthest;
            
            if (current_max <= i) return -1;
        }
    }
    
    return jumps;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = minJumps(arr, n);
    printf("Minimum jumps required: %d\n", result);
    
    return 0;
}
