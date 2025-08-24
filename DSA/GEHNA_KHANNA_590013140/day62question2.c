#include <stdio.h>
#include <stdlib.h>

struct Pair { int diff, val; };

int cmp(const void *a, const void *b) {
    struct Pair *p1=(struct Pair*)a, *p2=(struct Pair*)b;
    if (p1->diff == p2->diff) return p1->val - p2->val;
    return p1->diff - p2->diff;
}

int main() {
    int n,k,target;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++) scanf("%d", &arr[i]);
    scanf("%d%d", &target, &k);
    struct Pair pairs[n];
    for (int i=0;i<n;i++) {
        pairs[i].diff = abs(arr[i]-target);
        pairs[i].val = arr[i];
    }
    qsort(pairs,n,sizeof(struct Pair),cmp);
    for (int i=0;i<k;i++) printf("%d ", pairs[i].val);
    return 0;
}
