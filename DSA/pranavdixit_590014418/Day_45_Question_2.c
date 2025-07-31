#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

void enqueue1(int x) {
    q1[++rear1] = x;
}

void enqueue2(int x) {
    q2[++rear2] = x;
}

int areQueuesEqual() {
    if ((rear1 - front1) != (rear2 - front2))
        return 0;

    for (int i = 0; i <= (rear1 - front1); i++) {
        if (q1[front1 + i] != q2[front2 + i])
            return 0;
    }
    return 1;
}

int main() {
    enqueue1(1);
    enqueue1(2);
    enqueue1(3);

    enqueue2(1);
    enqueue2(2);
    enqueue2(3);

    if (areQueuesEqual())
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
