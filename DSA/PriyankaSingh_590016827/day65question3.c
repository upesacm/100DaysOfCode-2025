#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->end - ((Interval *)b)->end;
}

void minRemove(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compare);

    int count = 1;
    int lastEnd = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }
    printf("Remove %d → Remaining %d\n", n - count, count);
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    Interval arr[n];
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].start, &arr[i].end);

    minRemove(arr, n);
    return 0;
}
