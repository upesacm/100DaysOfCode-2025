#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void reverseFirstK(int queue[], int* front, int* rear, int k) {
    int stack[MAX], top = -1;

    // Step 1: Push first K elements into stack
    for (int i = 0; i < k; i++) {
        stack[++top] = queue[*front + i];
    }

    // Step 2: Pop from stack and overwrite queue
    for (int i = 0; i < k; i++) {
        queue[*front + i] = stack[top--];
    }

    // No need to move rest as we reversed in-place
}

void printQueue(int queue[], int front, int rear) {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[MAX] = {1, 2, 3, 4, 5};
    int front = 0, rear = 4;
    int k = 3;

    reverseFirstK(queue, &front, &rear, k);

    printQueue(queue, front, rear);  // Output: 3 2 1 4 5

    return 0;
}
