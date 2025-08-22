#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

typedef struct{int a[100000];int n;} MaxHeap;
typedef struct{int a[100000];int n;} MinHeap;

void maxHeapify(MaxHeap* h,int i){
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<h->n && h->a[l]>h->a[largest]) largest=l;
    if(r<h->n && h->a[r]>h->a[largest]) largest=r;
    if(largest!=i){swap(&h->a[i],&h->a[largest]);maxHeapify(h,largest);}
}

void minHeapify(MinHeap* h,int i){
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<h->n && h->a[l]<h->a[smallest]) smallest=l;
    if(r<h->n && h->a[r]<h->a[smallest]) smallest=r;
    if(smallest!=i){swap(&h->a[i],&h->a[smallest]);minHeapify(h,smallest);}
}

void maxPush(MaxHeap* h,int val){
    int i=h->n; h->a[i]=val; h->n++;
    while(i>0 && h->a[(i-1)/2]<h->a[i]){swap(&h->a[i],&h->a[(i-1)/2]); i=(i-1)/2;}
}

void minPush(MinHeap* h,int val){
    int i=h->n; h->a[i]=val; h->n++;
    while(i>0 && h->a[(i-1)/2]>h->a[i]){swap(&h->a[i],&h->a[(i-1)/2]); i=(i-1)/2;}
}

int maxPop(MaxHeap* h){
    int root=h->a[0];
    h->a[0]=h->a[h->n-1]; h->n--;
    if(h->n>0) maxHeapify(h,0);
    return root;
}

int minPop(MinHeap* h){
    int root=h->a[0];
    h->a[0]=h->a[h->n-1]; h->n--;
    if(h->n>0) minHeapify(h,0);
    return root;
}

int maxTop(MaxHeap* h){return h->a[0];}
int minTop(MinHeap* h){return h->a[0];}

void rebalance(MaxHeap* low, MinHeap* high){
    if(low->n>high->n+1){int x=maxPop(low); minPush(high,x);}
    else if(high->n>low->n){int x=minPop(high); maxPush(low,x);}
}

void addNumber(MaxHeap* low, MinHeap* high, int x){
    if(low->n==0 || x<=maxTop(low)) maxPush(low,x); else minPush(high,x);
    rebalance(low,high);
}

void printMedian(MaxHeap* low, MinHeap* high){
    if(low->n>high->n){printf("%d ", maxTop(low));}
    else{
        long long s = (long long)maxTop(low) + (long long)minTop(high);
        if((s&1)==0) printf("%lld ", s/2);
        else printf("%lld.5 ", s/2);
    }
}

int main(){
    MaxHeap low={.n=0}; MinHeap high={.n=0};
    int a1[]={5,15,1,3}; int n1=4;
    for(int i=0;i<n1;i++){addNumber(&low,&high,a1[i]); printMedian(&low,&high);} 
    printf("\n");
    low.n=0; high.n=0;
    int a2[]={1,2,3,4,5}; int n2=5;
    for(int i=0;i<n2;i++){addNumber(&low,&high,a2[i]); printMedian(&low,&high);} 
    return 0;
}
