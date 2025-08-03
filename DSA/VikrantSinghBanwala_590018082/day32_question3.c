#include<stdio.h>
int findXOR(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}
int main(){
    int arr1[] = {1, 2, 3};
    printf("%d\n", findXOR(arr1, 3));
    int arr2[] = {4, 5, 6};
    printf("%d\n", findXOR(arr2, 3));
    return 0;
}