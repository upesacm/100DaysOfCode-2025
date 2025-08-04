#include <stdio.h>
#include <stdbool.h>

bool areAllUnique(int queue[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (queue[i] == queue[j])
                return false; 
        }
    }
    return true;
}

int main() {
    int queue1[] = {1, 2, 3, 4};
    int size1 = 4;

    int queue2[] = {1, 2, 2, 3};
    int size2 = 4;

    printf("Queue1 all unique? %s\n", areAllUnique(queue1, size1) ? "True" : "False");
    printf("Queue2 all unique? %s\n", areAllUnique(queue2, size2) ? "True" : "False");

    return 0;
}

