#include <stdio.h>
#define MAX 100

int main() {
    int input[MAX];
    int temp[MAX];
    int top1 = -1, top2 = -1;
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    printf("Enter the elements (top to bottom):\n");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        input[++top1] = val;  
    }
    while (top1 != -1) {
        int tempVal = input[top1--]; 
        while (top2 != -1 && temp[top2] > tempVal) {
            input[++top1] = temp[top2--];  
        }

        temp[++top2] = tempVal;  
    }

    while (top2 != -1) {
        input[++top1] = temp[top2--];
    }

    printf("Sorted Stack (top to bottom):\n");
    for (int i = top1; i >= 0; i--) {
        printf("%d ", input[i]);
    }
    printf("\n");

    return 0;
}
