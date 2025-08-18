#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id,deadline,profit;
} Job;

int cmp(const void *a,const void *b){
    return ((Job*)b)->profit-((Job*)a)->profit;
}

int find(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}

int main(){
    int n,i,maxd=0;
    scanf("%d",&n);
    Job arr[n];
    for(i=0;i<n;i++) scanf("%d%d%d",&arr[i].id,&arr[i].deadline,&arr[i].profit);
    qsort(arr,n,sizeof(Job),cmp);
    for(i=0;i<n;i++) if(arr[i].deadline>maxd) maxd=arr[i].deadline;
    int parent[maxd+1];
    for(i=0;i<=maxd;i++) parent[i]=i;
    int cnt=0,profit=0;
    for(i=0;i<n;i++){
        int slot=find(parent,arr[i].deadline);
        if(slot>0){
            parent[slot]=find(parent,slot-1);
            cnt++;profit+=arr[i].profit;
        }
    }
    printf("%d jobs, Profit: %d",cnt,profit);
    return 0;
}
