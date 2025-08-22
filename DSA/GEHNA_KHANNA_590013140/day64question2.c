#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int w,v;
    double ratio;
} Item;

int cmp(const void *a,const void *b){
    double r=((Item*)b)->ratio-((Item*)a)->ratio;
    if(r>0) return 1;
    else if(r<0) return -1;
    return 0;
}

int main(){
    int n,i,cap;
    scanf("%d",&n);
    int w[n],v[n];
    for(i=0;i<n;i++) scanf("%d",&w[i]);
    for(i=0;i<n;i++) scanf("%d",&v[i]);
    scanf("%d",&cap);
    Item arr[n];
    for(i=0;i<n;i++){arr[i].w=w[i];arr[i].v=v[i];arr[i].ratio=(double)v[i]/w[i];}
    qsort(arr,n,sizeof(Item),cmp);
    double res=0;
    for(i=0;i<n && cap>0;i++){
        if(arr[i].w<=cap){res+=arr[i].v;cap-=arr[i].w;}
        else{res+=arr[i].ratio*cap;cap=0;}
    }
    printf("%.1f",res);
    return 0;
}
