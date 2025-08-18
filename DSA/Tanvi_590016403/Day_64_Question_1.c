#include <stdio.h>
#include <stdlib.h>

// ----------------- Problem 1: Activity Selection -----------------
typedef struct {
    int start, end;
} Activity;

int compareActivity(const void *a, const void *b) {
    return ((Activity *)a)->end - ((Activity *)b)->end; // sort by end time
}

int activitySelection(int start[], int end[], int n) {
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    qsort(activities, n, sizeof(Activity), compareActivity);

    int count = 1;  // first activity always selected
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}

// ----------------- Problem 2: Fractional Knapsack -----------------
typedef struct {
    int value, weight;
    double ratio;
} Item;

int compareItem(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio;
    double r2 = ((Item *)b)->ratio;
    return (r2 > r1) - (r2 < r1); // descending order
}

double fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].ratio = (double)values[i] / weights[i];
    }

    qsort(items, n, sizeof(Item), compareItem);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }
    return totalValue;
}

// ----------------- Problem 3: Job Scheduling for Profit -----------------
typedef struct {
    int id, deadline, profit;
} Job;

int compareJob(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit; // descending profit
}

int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compareJob);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) slot[i] = -1;

    int jobCount = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                jobCount++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job Scheduling Result: %d jobs, Profit: %d\n", jobCount, totalProfit);
}

// ----------------- MAIN FUNCTION -----------------
int main() {
    // Activity Selection Example
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start) / sizeof(start[0]);
    printf("Maximum activities: %d\n", activitySelection(start, end, n1));

    // Fractional Knapsack Example
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int capacity = 50;
    int n2 = sizeof(weights) / sizeof(weights[0]);
    printf("Maximum knapsack value: %.2f\n", fractionalKnapsack(weights, values, n2, capacity));

    // Job Scheduling Example
    Job jobs[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n3 = sizeof(jobs) / sizeof(jobs[0]);
    jobScheduling(jobs, n3);

    return 0;
}
