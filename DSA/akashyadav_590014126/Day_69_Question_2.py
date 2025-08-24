def can_partition(arr):
    total = sum(arr)
    
    if total % 2 != 0:
        return False
    
    target = total // 2
    n = len(arr)
    
    dp = [False] * (target + 1)
    dp[0] = True
    
    for num in arr:
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]
    
    return dp[target]
