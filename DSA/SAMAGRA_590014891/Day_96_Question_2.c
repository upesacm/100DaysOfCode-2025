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

int main() {
    int arr[]={3,34,4,12,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=9;
    if(subsetSum(arr,n,target)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
