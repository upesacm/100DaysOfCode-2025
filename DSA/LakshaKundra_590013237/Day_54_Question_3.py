def numSubarrayProductLessThanK(nums, k):
    if k <= 1:
        return 0
    prod = 1
    left = 0
    ans = 0
    for right in range(len(nums)):
        prod *= nums[right]
        while prod >= k:
            prod //= nums[left]
            left += 1
        ans += right - left + 1
    return ans

print(numSubarrayProductLessThanK([10, 5, 2, 6], 100))
print(numSubarrayProductLessThanK([1, 2, 3], 0))
