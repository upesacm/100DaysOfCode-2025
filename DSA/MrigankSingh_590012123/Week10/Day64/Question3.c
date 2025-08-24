#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

void jobScheduling(Job jobs[], int n, int* count, int* totalProfit) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    int* slots = (int*)malloc((maxDeadline + 1) * sizeof(int));
    for (int i = 0; i <= maxDeadline; i++) {
        slots[i] = -1;
    }
    
    qsort(jobs, n, sizeof(Job), compare);
    
    *count = 0;
    *totalProfit = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                *totalProfit += jobs[i].profit;
                (*count)++;
                break;
            }
        }
    }
    
    free(slots);
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    
    Job* jobs = (Job*)malloc(n * sizeof(Job));
    
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Enter deadline and profit for job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }
    
    int count, totalProfit;
    jobScheduling(jobs, n, &count, &totalProfit);
    
    printf("Scheduled jobs: %d\n", count);
    printf("Total profit: %d\n", totalProfit);
    
    free(jobs);
    return 0;
}
