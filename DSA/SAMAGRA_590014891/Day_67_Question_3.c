#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start,end;
} Meeting;

int compare(const void *a,const void *b) {
    return ((Meeting*)a)->end - ((Meeting*)b)->end;
}

int maxMeetings(int start[],int end[],int n) {
    Meeting m[n];
    for(int i=0;i<n;i++) { m[i].start=start[i]; m[i].end=end[i]; }
    qsort(m,n,sizeof(Meeting),compare);

    int count=1,last=m[0].end;
    for(int i=1;i<n;i++) {
        if(m[i].start>last) {
            count++;
            last=m[i].end;
        }
    }
    return count;
}

int main() {
    int start[]={1,3,0,5,8,5};
    int end[]={2,4,6,7,9,9};
    printf("%d\n", maxMeetings(start,end,6));
    return 0;
}
