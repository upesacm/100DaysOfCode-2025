#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int pq[MAX], size = 0;

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

void insert(int val) {
    pq[size++] = val;
    qsort(pq, size, sizeof(int), cmp);
}

int extractMax() {
    if (size == 0) return -1;
    int max = pq[0];
    for (int i = 1; i < size; i++) pq[i - 1] = pq[i];
    size--;
    return max;
}

int main() {
    int choice, val;
    while (1) {
        printf("1.Insert 2.ExtractMax 3.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            insert(val);
        } else if (choice == 2) {
            printf("%d\n", extractMax());
        } else break;
    }
    return 0;
}
