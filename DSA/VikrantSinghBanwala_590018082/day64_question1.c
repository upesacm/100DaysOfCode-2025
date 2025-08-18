#include <stdio.h>

void activitySelection(int start[], int end[], int n) {
    int i, j;
    int count = 1;
    int lastEndTime = end[0];

    for (i = 1; i < n; i++) {
        if (start[i] >= lastEndTime) {
            count++;
            lastEndTime = end[i];
        }
    }
    printf("%d\n", count);
}

int main() {
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    
    int start2[] = {1, 2, 3};
    int end2[] = {2, 3, 4};
    int n2 = sizeof(start2) / sizeof(start2[0]);

    activitySelection(start1, end1, n1);
    activitySelection(start2, end2, n2);

    return 0;
}
