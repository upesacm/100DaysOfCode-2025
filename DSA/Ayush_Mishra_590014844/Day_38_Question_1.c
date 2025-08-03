#include <stdio.h>
#define MAX 100

int main() {
    int n, arr[MAX], res[MAX], stack[MAX];
    int top = -1;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i = n - 1; i >= 0; i--) {
        while(top != -1 && stack[top] <= arr[i]) {
            top--;
        }
        res[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];
    }
    
    printf("Next Greater Elements:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    
    return 0;
}
