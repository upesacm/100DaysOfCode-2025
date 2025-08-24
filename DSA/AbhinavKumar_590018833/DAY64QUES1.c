// 1. Select Maximum Activities
// A problem that demonstrates activity selection optimization and teaches interval scheduling algorithms using greedy approach for efficient resource allocation and time management operations.

// Given start and end times of activities, find the maximum number of non-overlapping activities you can perform using greedy selection strategy. This operation is fundamental in interval scheduling and resource optimization where you need to maximize activity participation within time constraints efficiently. The technique uses earliest finish time greedy approach to always select activities that end first, as this leaves maximum room for subsequent activities. This concept is essential in project management, meeting scheduling, and resource allocation where maximizing concurrent operations enables optimal time utilization and efficient workflow management in time-sensitive environments.

// This demonstrates activity selection algorithms and interval scheduling techniques that are crucial for resource optimization and efficient time management operations.

// Your task: Implement greedy activity selection using earliest finish time strategy to maximize non-overlapping activity participation with optimal scheduling.

// Examples
// Input:

// start = [1, 3, 0, 5, 8, 5]
// end = [2, 4, 6, 7, 9, 9]
// Output:

// 4
// Input:

// start = [1, 2, 3]
// end = [2, 3, 4]
// Output:

// 3


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compareActivities(const void* a, const void* b) {
    Activity* activityA = (Activity*)a;
    Activity* activityB = (Activity*)b;
    return activityA->end - activityB->end;
}


void findMaxActivities(int start[], int end[], int n) {
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    qsort(activities, n, sizeof(Activity), compareActivities);

    printf("The following activities are selected:\n");

    int i = 0; 
    printf("(%d, %d)\n", activities[i].start, activities[i].end);
    int count = 1;

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].end) {
            printf("(%d, %d)\n", activities[j].start, activities[j].end);
            i = j; 
            count++;
        }
    }
    
    printf("\nMaximum number of activities: %d\n", count);
}

int main() {
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    findMaxActivities(start1, end1, n1);
    printf("\n");

    
    int start2[] = {1, 2, 3};
    int end2[] = {2, 3, 4};
    int n2 = sizeof(start2) / sizeof(start2[0]);
    
    findMaxActivities(start2, end2, n2);

    return 0;
}