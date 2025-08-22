#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int val;
    int dist;
} Node;

void swap(Node *a, Node *b) {
    Node t=*a; *a=*b; *b=t;
}

void heapify(Node heap[], int n, int i) {
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && (heap[l].dist>heap[largest].dist || 
       (heap[l].dist==heap[largest].dist && heap[l].val>heap[largest].val)))
        largest=l;
    if(r<n && (heap[r].dist>heap[largest].dist || 
       (heap[r].dist==heap[largest].dist && heap[r].val>heap[largest].val)))
        largest=r;
    if(largest!=i){swap(&heap[i],&heap[largest]);heapify(heap,n,largest);}
}

void buildHeap(Node heap[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(heap,n,i);
}

int main() {
    int n, target, k;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
     printf("enter the elements\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
     printf("enter value of target\n");
    scanf("%d",&target);
      printf("enter value of k\n");
    scanf("%d",&k);

    Node heap[1000]; int heapSize=0;
    for(int i=0;i<n;i++) {
        Node node; node.val=arr[i]; node.dist=abs(arr[i]-target);
        if(heapSize<k) {
            heap[heapSize++]=node;
            buildHeap(heap,heapSize);
        } else if(node.dist<heap[0].dist || (node.dist==heap[0].dist && node.val<heap[0].val)) {
            heap[0]=node;
            heapify(heap,heapSize,0);
        }
    }

    int result[1000], m=0;
    for(int i=0;i<heapSize;i++) result[m++]=heap[i].val;

    for(int i=0;i<m-1;i++) {
        for(int j=i+1;j<m;j++) {
            if(result[i]>result[j]) {
                int t=result[i]; result[i]=result[j]; result[j]=t;
            }
        }
    }

    printf("Output:\n[");
    for(int i=0;i<m;i++) {
        printf("%d",result[i]);
        if(i<m-1) printf(", ");
    }
    printf("]\n");
    return 0;
}
