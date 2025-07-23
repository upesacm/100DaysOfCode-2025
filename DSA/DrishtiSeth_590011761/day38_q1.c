
#include <stdio.h>

void nextGreaterElement(int arr[], int n) {
    int stack[n], top = -1, res[n];
    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i]) top--;
        if (top == -1) res[i] = -1;
        else res[i] = stack[top];
        stack[++top] = arr[i];
    }
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreaterElement(arr, n);
    return 0;
}
