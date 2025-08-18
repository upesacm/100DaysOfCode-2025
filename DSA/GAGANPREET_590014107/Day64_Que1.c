#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int start;
    int end;
} Activity;


int compare(const void* a, const void* b) {
    Activity* actA = (Activity*)a;
    Activity* actB = (Activity*)b;
    return actA->end - actB->end;
}


int selectMaxActivities(int start[], int end[], int n) {
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    
    qsort(activities, n, sizeof(Activity), compare);

    int count = 1;  
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main() {
    
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[] =   {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    printf("Max activities (Example 1): %d\n", selectMaxActivities(start1, end1, n1));  // ➜ 4

    
    int start2[] = {1, 2, 3};
    int end2[] =   {2, 3, 4};
    int n2 = sizeof(start2) / sizeof(start2[0]);
    printf("Max activities (Example 2): %d\n", selectMaxActivities(start2, end2, n2));  // ➜ 3

    return 0;
}
