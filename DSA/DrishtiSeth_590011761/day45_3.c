#include <stdio.h>
#define SIZE 100
int queue[SIZE];
int front = 0, rear = -1;

int maxQueue() {
    int max = queue[front];
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i] > max) max = queue[i];
    }
    return max;
}

int main() {
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        queue[++rear] = val;
    }
    printf("%d\n", maxQueue());
    return 0;
}