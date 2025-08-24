# Split Array into Equal Sum
def can_partition(arr):
    total = sum(arr)
    if total % 2 != 0:
        return False
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    for num in arr:
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]
    return dp[target]

arr = list(map(int, input().split()))
print(str(can_partition(arr)).lower())
