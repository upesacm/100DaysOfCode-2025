#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, end;
};

int cmp(const void *a, const void *b) {
    return ((struct Activity*)a)->end - ((struct Activity*)b)->end;
}

int activitySelection(int start[], int end[], int n) {
    struct Activity activities[n];
    for(int i=0;i<n;i++) {
        activities[i].start=start[i];
        activities[i].end=end[i];
    }
    qsort(activities,n,sizeof(struct Activity),cmp);
    int count=1,last=0;
    for(int i=1;i<n;i++) {
        if(activities[i].start>=activities[last].end) {
            count++;
            last=i;
        }
    }
    return count;
}

int main() {
    int n;
    printf("enter number of elements\n");
    scanf("%d",&n);
    int start[n],end[n];
    printf("enter elements in start \n");
    for(int i=0;i<n;i++) scanf("%d",&start[i]);
     printf("enter elements in end \n");
    for(int i=0;i<n;i++) scanf("%d",&end[i]);
    printf("%d",activitySelection(start,end,n));
    return 0;
}
