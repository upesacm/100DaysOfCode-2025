#include <stdio.h>
#include <stdbool.h>

bool areHeapsIdentical(int arr1[], int arr2[], int n1, int n2) {
    if (n1 != n2) 
        return false;  // Different sizes → not identical
    
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) 
            return false; // Mismatch found → not identical
    }
    return true; // All elements matched
}

int main() {
    int arr1[] = {10, 9, 8};
    int arr2[] = {10, 9, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    if (areHeapsIdentical(arr1, arr2, n1, n2))
        printf("true\n");
    else
        printf("false\n");

    int arr3[] = {10, 9, 8};
    int arr4[] = {10, 8, 9};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    if (areHeapsIdentical(arr3, arr4, n3, n4))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
