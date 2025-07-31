#include <stdio.h>
#define MAX 100
int main() {
    int Q1[MAX], Q2[MAX], merged[MAX];
    int n1, n2, i, j, k = 0;
    printf("Enter number of elements in Queue 1: ");
    scanf("%d", &n1);
    printf("Enter %d elements for Queue 1:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &Q1[i]);
        merged[k++] = Q1[i]; 
    }
    printf("Enter number of elements in Queue 2: ");
    scanf("%d", &n2);
    printf("Enter %d elements for Queue 2:\n", n2);
    for (j = 0; j < n2; j++) {
        scanf("%d", &Q2[j]);
        merged[k++] = Q2[j];  
    }

    // Output merged queue
    printf("Merged Queue: ");
    for (i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
