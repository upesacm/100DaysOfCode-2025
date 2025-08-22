#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id, deadline, profit;
};

int cmp(const void *a,const void *b){
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int main(){
    int n;
    printf("Enter number of jobs: ");
    scanf("%d",&n);
    struct Job jobs[n];
    printf("Enter job id, deadline, profit for each job:\n");
    for(int i=0;i<n;i++) scanf("%d %d %d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
    qsort(jobs,n,sizeof(struct Job),cmp);
    int maxDeadline=0;
    for(int i=0;i<n;i++) if(jobs[i].deadline>maxDeadline) maxDeadline=jobs[i].deadline;
    int slot[maxDeadline+1];
    for(int i=0;i<=maxDeadline;i++) slot[i]=-1;
    int count=0,totalProfit=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(slot[j]==-1){
                slot[j]=jobs[i].id;
                count++;
                totalProfit+=jobs[i].profit;
                break;
            }
        }
    }
    printf("%d jobs, Profit: %d\n",count,totalProfit);
    printf("Selected job sequence: ");
    for(int i=1;i<=maxDeadline;i++){
        if(slot[i]!=-1) printf("J%d ",slot[i]);
    }
    printf("\n");
    return 0;
}
