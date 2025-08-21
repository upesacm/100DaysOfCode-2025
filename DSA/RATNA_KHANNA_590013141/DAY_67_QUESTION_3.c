#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start, end;
};

int compare(const void *a, const void *b) {
    return ((struct Meeting*)a)->end - ((struct Meeting*)b)->end;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d",&n);

    struct Meeting meetings[n];
    printf("Enter start times:\n");
    for(int i=0;i<n;i++) scanf("%d",&meetings[i].start);
    printf("Enter end times:\n");
    for(int i=0;i<n;i++) scanf("%d",&meetings[i].end);

    qsort(meetings,n,sizeof(struct Meeting),compare);

    int count=1, last_end=meetings[0].end;
    for(int i=1;i<n;i++) {
        if(meetings[i].start>=last_end) {
            count++;
            last_end=meetings[i].end;
        }
    }

    printf("Maximum number of non-overlapping meetings: %d\n",count);
    return 0;
}
