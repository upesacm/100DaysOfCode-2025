#include <stdio.h>
#include <stdbool.h>

bool areElementsUnique(int queue[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (queue[i] == queue[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int queue[100], size;

    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }

    if (areElementsUnique(queue, size)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
