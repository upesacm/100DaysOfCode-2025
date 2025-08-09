def numSubarraysWithSum(nums, goal):
    prefix_sum = 0
    count = {0: 1}
    ans = 0
    for num in nums:
        prefix_sum += num
        ans += count.get(prefix_sum - goal, 0)
        count[prefix_sum] = count.get(prefix_sum, 0) + 1
    return ans

print(numSubarraysWithSum([1,0,1,0,1], 2))
print(numSubarraysWithSum([0,0,0,0,0], 0))
