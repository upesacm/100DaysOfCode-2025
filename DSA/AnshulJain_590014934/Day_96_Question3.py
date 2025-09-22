n=int(input())
arr=list(map(int,input().split()))
total=sum(arr)
if total%2!=0:
    print("No")
else:
    target=total//2
    dp=[[False]*(target+1) for _ in range(n+1)]
    for i in range(n+1):
        dp[i][0]=True
    for i in range(1,n+1):
        for s in range(1,target+1):
            if arr[i-1]<=s:
                dp[i][s]=dp[i-1][s] or dp[i-1][s-arr[i-1]]
            else:
                dp[i][s]=dp[i-1][s]
    print("Yes" if dp[n][target] else "No")
