#include <stdio.h>
#include <stdbool.h>
bool canPartition(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%2!=0) return false;
    int target=sum/2;
    bool dp[n+1][target+1];
    for(int i=0;i<=n;i++) dp[i][0]=true;
    for(int j=1;j<=target;j++) dp[0][j]=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j) dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    if(canPartition(arr,n)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
