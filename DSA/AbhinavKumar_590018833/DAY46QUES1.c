#include <stdio.h>
#define SIZE 100

int findMin(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }

    int min = queue[front];
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i] < min)
            min = queue[i];
    }
    return min;
}

int main() {
    int queue[SIZE] = {4, 2, 7, 1};
    int front = 0, rear = 3;

    int minElement = findMin(queue, front, rear);
    if (minElement != -1)
        printf("Minimum element in the queue is: %d\n", minElement);

    return 0;
}
