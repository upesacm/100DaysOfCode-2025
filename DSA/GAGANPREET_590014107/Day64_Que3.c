#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobB->profit - jobA->profit;
}


void jobScheduling(Job jobs[], int n) {
    
    qsort(jobs, n, sizeof(Job), compare);


    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    
    bool slot[MAX] = {false};
    int jobSequence[MAX];
    int count = 0, totalProfit = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                jobSequence[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    
    printf("%d jobs, Profit: %d\n", count, totalProfit);
}

int main() {
    
    Job jobs1[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n1 = sizeof(jobs1) / sizeof(jobs1[0]);
    jobScheduling(jobs1, n1);

    
    Job jobs2[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}};
    int n2 = sizeof(jobs2) / sizeof(jobs2[0]);
    jobScheduling(jobs2, n2);

    return 0;
}
