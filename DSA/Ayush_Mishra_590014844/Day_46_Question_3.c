#include <stdio.h>
#define SIZE 200

int main() {
    int q1[SIZE], q2[SIZE], merged[SIZE];
    int n1, n2, rear1 = -1, rear2 = -1, rearM = -1;

    printf("Enter size of Queue 1: ");
    scanf("%d", &n1);

    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &q1[++rear1]);
        merged[++rearM] = q1[rear1];
    }

    printf("Enter size of Queue 2: ");
    scanf("%d", &n2);

    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &q2[++rear2]);
        merged[++rearM] = q2[rear2];
    }

    printf("Merged Queue: ");
    for (int i = 0; i <= rearM; i++) {
        printf("%d ", merged[i]);
    }

    printf("\n");
    return 0;
}
