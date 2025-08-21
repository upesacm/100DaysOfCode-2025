#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t=*a; *a=*b; *b=t;
}

void heapify(int heap[], int n, int i) {
    int smallest=i, l=2*i+1, r=2*i+2;
    if(l<n && heap[l]<heap[smallest]) smallest=l;
    if(r<n && heap[r]<heap[smallest]) smallest=r;
    if(smallest!=i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap,n,smallest);
    }
}

int extractMin(int heap[], int *n) {
    int root=heap[0];
    heap[0]=heap[*n-1];
    (*n)--;
    heapify(heap,*n,0);
    return root;
}

void insertHeap(int heap[], int *n, int val) {
    (*n)++;
    int i=*n-1;
    heap[i]=val;
    while(i!=0 && heap[(i-1)/2]>heap[i]) {
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

int main() {
    int n;
    printf("Enter number of ropes: ");
    scanf("%d",&n);

    int heap[1000];
    printf("Enter rope lengths:\n");
    for(int i=0;i<n;i++) scanf("%d",&heap[i]);

    for(int i=n/2-1;i>=0;i--) heapify(heap,n,i);

    int cost=0;
    while(n>1) {
        int first=extractMin(heap,&n);
        int second=extractMin(heap,&n);
        int sum=first+second;
        cost+=sum;
        insertHeap(heap,&n,sum);
    }

    printf("Minimum total cost: %d\n",cost);
    return 0;
}
