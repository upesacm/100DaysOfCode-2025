#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int compare(const void *a, const void *b) {
    return ((Meeting *)a)->end - ((Meeting *)b)->end;
}

int main() {
    int n;
    scanf("%d", &n);
    Meeting meetings[n];
    for (int i = 0; i < n; i++) scanf("%d", &meetings[i].start);
    for (int i = 0; i < n; i++) scanf("%d", &meetings[i].end);

    qsort(meetings, n, sizeof(Meeting), compare);

    int count = 1, lastEnd = meetings[0].end;
    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    printf("%d\n", count);
    return 0;
}
