#include<stdio.h>
#include<stdbool.h>
bool hasPairWithSum(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == x) {
            return true;
        } else if (currentSum < x) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}
int main() {
    int arr1[] = {1, 4, 6, 8, 10, 45};
    int x1 = 16;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("%s\n", hasPairWithSum(arr1, n1, x1) ? "true" : "false");
    int arr2[] = {1, 2, 3, 4, 6};
    int x2 = 10;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%s\n", hasPairWithSum(arr2, n2, x2) ? "true" : "false");
    return 0;
}
