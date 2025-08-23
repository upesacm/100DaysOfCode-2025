#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int cmp(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return (m1->end - m2->end);
}

int main(void) {
    int n;
    scanf("%d", &n);
    Meeting *meetings = (Meeting *)malloc(n * sizeof(Meeting));

    for (int i = 0; i < n; i++) scanf("%d", &meetings[i].start);
    for (int i = 0; i < n; i++) scanf("%d", &meetings[i].end);

    qsort(meetings, n, sizeof(Meeting), cmp);

    int count = 1;
    int lastEnd = meetings[0].end;
    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    printf("%d\n", count);
    free(meetings);
    return 0;
}
