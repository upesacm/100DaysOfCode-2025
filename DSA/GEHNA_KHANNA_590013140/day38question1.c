#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void nextGreaterElement(int arr[], int n) {
    int result[n];
    int stack[MAX];
    int top = -1;


    for (int i = 0; i < n; i++)
        result[i] = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > arr[stack[top]]) {
            int index = stack[top--];
            result[index] = arr[i];
        }
        stack[++top] = i;
    }

    printf("Next Greater Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    nextGreaterElement(arr, n);

    return 0;
}
