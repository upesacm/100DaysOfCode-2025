//Return the result ofXORing all elements in the array.
#include<stdio.h>
int xorArray(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}
int main() {
    printf("Enter the number of elements in the array:\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int xorResult = xorArray(arr, n);
    printf("The result of XORing all elements is: %d\n", xorResult);
    return 0;


}