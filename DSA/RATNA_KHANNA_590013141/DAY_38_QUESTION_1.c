#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int arr[], int n) {
    int result[n];     
    int stack[n];      
    int top = -1;    

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > arr[stack[top]]) {
            int index = stack[top--];     
            result[index] = arr[i];      
        }
        stack[++top] = i;  
    }

    while (top != -1) {
        result[stack[top--]] = -1;
    }

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    nextGreaterElement(arr, n);

    return 0;
}
