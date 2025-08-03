#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1)
        queue[++rear] = x;
}

void countOccurrences() {
    int visited[MAX] = {0};

    for (int i = front; i <= rear; i++) {
        if (visited[i])
            continue;

        int count = 1;
        for (int j = i + 1; j <= rear; j++) {
            if (queue[i] == queue[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d: %d\n", queue[i], count);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(2);
    enqueue(3);
    enqueue(1);
    enqueue(1);

    countOccurrences(); // Output: 1: 3, 2: 2, 3: 1
    return 0;
}
