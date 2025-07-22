//Find the single non repeating number using XOR operator.
#include<stdio.h>
int findSingle(int arr[], int size) {
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
    int single = findSingle(arr, n);
    printf("The single non-repeating element is: %d\n", single);

    return 0;
}

