#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int isArrival;
} Event;

int compare(const void* a, const void* b) {
    return ((Event*)a)->time - ((Event*)b)->time;
}

int minPlatforms(int arr[], int dep[], int n) {
    Event* events = (Event*)malloc(2 * n * sizeof(Event));
    for (int i = 0; i < n; i++) {
        events[2 * i].time = arr[i];
        events[2 * i].isArrival = 1;
        events[2 * i + 1].time = dep[i];
        events[2 * i + 1].isArrival = 0;
    }
    
    qsort(events, 2 * n, sizeof(Event), compare);
    
    int maxPlatforms = 0;
    int currentPlatforms = 0;
    
    for (int i = 0; i < 2 * n; i++) {
        if (events[i].isArrival) {
            currentPlatforms++;
            if (currentPlatforms > maxPlatforms) {
                maxPlatforms = currentPlatforms;
            }
        } else {
            currentPlatforms--;
        }
    }
    
    free(events);
    return maxPlatforms;
}

int main() {
    int n;
    printf("Enter number of trains: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    int* dep = (int*)malloc(n * sizeof(int));
    
    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter departure times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &dep[i]);
    }
    
    int result = minPlatforms(arr, dep, n);
    printf("Minimum platforms needed: %d\n", result);
    
    free(arr);
    free(dep);
    return 0;
}
