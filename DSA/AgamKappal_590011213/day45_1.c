#include <stdio.h>
#define SIZE 100
int front = 0, rear = -1;
int queue[SIZE];

int sumQueue() {
    int sum = 0;
    for (int i = front; i <= rear; i++) {
        sum += queue[i];
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }
    printf("%d\n", sumQueue());
    return 0;
}