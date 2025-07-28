#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int val) {
    queue[++rear] = val;
}

int dequeue() {
    return queue[front++];
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, k;
    printf("enter number of elements\n");
    scanf("%d", &n);
    printf("enter the values\n");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }
    printf("enter values of k\n");
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        push(dequeue());
    }
    while (top != -1) {
        enqueue(pop());
    }
    for (int i = 0; i < n - k; i++) {
        enqueue(dequeue());
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}
