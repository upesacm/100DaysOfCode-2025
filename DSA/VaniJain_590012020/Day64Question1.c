#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int start, end;
} Activity;
int compare(const void *a, const void *b) 
{
    Activity *actA = (Activity *)a;
    Activity *actB = (Activity *)b;
    return actA->end - actB->end;
}
int activitySelection(Activity activities[], int n) 
{
    qsort(activities, n, sizeof(Activity), compare);
    int count = 1; 
    int lastEnd = activities[0].end;
    for (int i = 1; i < n; i++) 
    {
        if (activities[i].start >= lastEnd) 
        {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}
int main() 
{
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    Activity activities[n];
    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }
    int maxActivities = activitySelection(activities, n);
    printf("Maximum number of non-overlapping activities: %d\n", maxActivities);
    return 0;
}
