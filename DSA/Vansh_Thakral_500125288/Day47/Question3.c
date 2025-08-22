#include <stdio.h>

void findFrontRear(int queue[], int size) {
    if (size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front: %d, Rear: %d\n", queue[0], queue[size - 1]);
}

int main() {
    int queue1[] = {10, 20, 30};
    int size1 = 3;

    findFrontRear(queue1, size1);  

    int queue2[] = {};
    int size2 = 0;

    findFrontRear(queue2, size2);  

    return 0;
}

