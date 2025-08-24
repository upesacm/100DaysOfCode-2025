def canPartition(nums):
    s=sum(nums)
    if s%2: return False
    t=s//2
    dp={0}
    for n in nums:
        dp|={x+n for x in dp}
    return t in dp

print(canPartition([1,2,3,5]))
print(canPartition([1,5,11,5]))
