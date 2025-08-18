#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Activity;

int cmp(const void *a, const void *b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

int main() {
    int n,i,count=1,last=0;
    scanf("%d",&n);
    Activity arr[n];
    for(i=0;i<n;i++) scanf("%d",&arr[i].start);
    for(i=0;i<n;i++) scanf("%d",&arr[i].end);
    qsort(arr,n,sizeof(Activity),cmp);
    for(i=1;i<n;i++) if(arr[i].start>=arr[last].end){count++;last=i;}
    printf("%d",count);
    return 0;
}
