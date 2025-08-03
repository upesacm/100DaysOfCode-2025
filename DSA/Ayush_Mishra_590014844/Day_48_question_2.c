#include <stdio.h>

int main() {
    int n, i, j, isUnique = 1;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    int queue[n];
    printf("Enter %d queue elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] == queue[j]) {
                isUnique = 0;
                break;
            }
        }
        if (!isUnique) break;
    }

    if (isUnique)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
