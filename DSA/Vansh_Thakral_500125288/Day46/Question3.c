#include <stdio.h>

void mergeQueues(int q1[], int n1, int q2[], int n2, int merged[]) {
    int k = 0;
    for(int i = 0; i < n1; i++)
        merged[k++] = q1[i];
    for(int i = 0; i < n2; i++)
        merged[k++] = q2[i];
}

int main() {
    int q1[] = {1, 2};
    int q2[] = {3, 4};
    int merged[100];
    int n1 = sizeof(q1)/sizeof(q1[0]);
    int n2 = sizeof(q2)/sizeof(q2[0]);

    mergeQueues(q1, n1, q2, n2, merged);

    printf("Merged Queue: ");
    for(int i = 0; i < n1+n2; i++)
        printf("%d ", merged[i]);
    printf("\n");

    return 0;
}

