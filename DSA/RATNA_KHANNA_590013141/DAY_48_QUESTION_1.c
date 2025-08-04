#include <stdio.h>

#define MAX 100

void removeOccurrences(int queue[], int *size, int x) {
    int temp[MAX];
    int j = 0;

    for (int i = 0; i < *size; i++) {
        if (queue[i] != x) {
            temp[j++] = queue[i];
        }
    }

    for (int i = 0; i < j; i++) {
        queue[i] = temp[i];
    }

    *size = j;
}

int main() {
    int queue[MAX], size, x;

    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }
    scanf("%d", &x);

    removeOccurrences(queue, &size, x);

    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
