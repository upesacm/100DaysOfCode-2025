#include <stdio.h>

void nextGreaterElement(int arr[], int n) {
    int stack[n], top = -1;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i]) {
            top--; 
        }

        result[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i]; 
    }

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}


int main() {
    int arr1[] = {4, 5, 2, 25};
    int arr2[] = {13, 7, 6, 12};

    nextGreaterElement(arr1, 4);
    nextGreaterElement(arr2, 4);

    return 0;
}

