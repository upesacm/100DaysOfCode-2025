#include <stdio.h>

int findUnique(int arr[], int size) {
    int result = 0;
    for(int i = 0; i < size; i++) {
        result ^= arr[i]; 
    }
    return result;
}

int main() {
    int arr[] = {5,1,1,5,7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int unique = findUnique(arr, size);
    printf("The unique element is: %d\n", unique);

    return 0;
}
