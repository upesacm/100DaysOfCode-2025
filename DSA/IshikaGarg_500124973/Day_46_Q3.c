#include <stdio.h>
#define SIZE 100

int q1[SIZE], q2[SIZE], q3[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
int rear3 = -1;

void enqueueQ1(int val) {
    if (rear1 == SIZE - 1)
        printf("Queue1 is full\n");
    else {
        if (front1 == -1)
            front1 = 0;
        q1[++rear1] = val;
    }
}

void enqueueQ2(int val) {
    if (rear2 == SIZE - 1)
        printf("Queue2 is full\n");
    else {
        if (front2 == -1)
            front2 = 0;
        q2[++rear2] = val;
    }
}

void mergeQueues() {
    // Merge q1
    for (int i = front1; i <= rear1; i++) {
        q3[++rear3] = q1[i];
    }
    // Merge q2
    for (int i = front2; i <= rear2; i++) {
        q3[++rear3] = q2[i];
    }
}

void displayMergedQueue() {
    printf("Merged Queue: ");
    for (int i = 0; i <= rear3; i++)
        printf("%d ", q3[i]);
    printf("\n");
}

int main() {
    // Q1 = [1, 2], Q2 = [3, 4]
    enqueueQ1(1);
    enqueueQ1(2);

    enqueueQ2(3);
    enqueueQ2(4);

    mergeQueues();
    displayMergedQueue();

    return 0;
}

