#include <stdio.h>
#include <limits.h>

int findMin(int queue[], int front, int rear) {
    int min = INT_MAX;
    for (int i = front; i <= rear; i++) {
        if (queue[i] < min)
            min = queue[i];
    }
    return min;
}

int main() {
    int queue[] = {4, 2, 7, 1};
    int front = 0, rear = 3;
    printf("%d\n", findMin(queue, front, rear));
    return 0;
}
