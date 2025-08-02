#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

void removeAllOccurrences(int x) {
    int temp[MAX], t = -1;
    for (int i = front; i <= rear; i++) {
        if (queue[i] != x)
            temp[++t] = queue[i];
    }

    front = 0;
    rear = t;
    for (int i = 0; i <= t; i++)
        queue[i] = temp[i];
}

void printQueue() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(2);
    enqueue(4);

    removeAllOccurrences(2);
    printQueue(); // Output: 1 3 4
    return 0;
}
