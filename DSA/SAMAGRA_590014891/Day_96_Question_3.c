#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int arr[], int n, int target) {
    bool dp[n+1][target+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j==0) dp[i][j]=true;
            else if(i==0) dp[i][j]=false;
            else if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
}

bool canPartition(int arr[], int n) {
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%2!=0) return false;
    return subsetSum(arr,n,sum/2);
}

int main() {
    int arr[]={1,5,11,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(canPartition(arr,n)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
