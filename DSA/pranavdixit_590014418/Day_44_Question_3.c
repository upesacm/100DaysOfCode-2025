#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int isEmpty() {
    return front > rear;
}

int main() {
    if (isEmpty())
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
