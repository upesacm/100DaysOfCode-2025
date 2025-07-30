#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void reverseK(int queue[], int n, int k) {
    int stack[MAX], top = -1;

    // Push first k elements into stack
    for (int i = 0; i < k; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack to queue
    for (int i = 0; i < k; i++) {
        queue[i] = stack[top--];
    }

    // Print the modified queue
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[] = {1, 2, 3, 4, 5};
    int k = 3;
    int n = sizeof(queue)/sizeof(queue[0]);

    reverseK(queue, n, k);
    return 0;
}
