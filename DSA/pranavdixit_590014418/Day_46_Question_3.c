#include <stdio.h>

#define MAX 200

int q1[MAX], q2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

void enqueue1(int x) {
    if (rear1 < MAX - 1) q1[++rear1] = x;
}

void enqueue2(int x) {
    if (rear2 < MAX - 1) q2[++rear2] = x;
}

void mergeQueues() {
    for (int i = front2; i <= rear2; i++)
        enqueue1(q2[i]);
}

void printQ1() {
    for (int i = front1; i <= rear1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    enqueue1(1);
    enqueue1(2);
    enqueue2(3);
    enqueue2(4);
    mergeQueues();
    printQ1();
    return 0;
}
