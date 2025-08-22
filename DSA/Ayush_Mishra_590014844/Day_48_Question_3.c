#include <stdio.h>

int main() {
    int n, i, j, count;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    int queue[n], printed[n];
    printf("Enter %d queue elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        printed[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (!printed[i]) {
            count = 1;
            for (j = i + 1; j < n; j++) {
                if (queue[i] == queue[j]) {
                    count++;
                    printed[j] = 1;
                }
            }
            printf("%d: %d\n", queue[i], count);
        }
    }
    return 0;
}
