#include <stdio.h>

void mergeQueues(int q1[], int size1, int q2[], int size2, int merged[]) {
    for (int i = 0; i < size1; i++)
        merged[i] = q1[i];
    for (int i = 0; i < size2; i++)
        merged[size1 + i] = q2[i];
}

int main() {
    int q1[100], q2[100], merged[200];
    int size1, size2;

    printf("Enter number of elements in first queue: ");
    scanf("%d", &size1);
    printf("Enter %d elements for first queue:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &q1[i]);
    }

    printf("Enter number of elements in second queue: ");
    scanf("%d", &size2);
    printf("Enter %d elements for second queue:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &q2[i]);
    }

    mergeQueues(q1, size1, q2, size2, merged);

    printf("Merged Queue: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
