def numSubarrayProductLessThanK(nums, k):
    if k <= 1:
        return 0

    prod = 1
    left = 0
    count = 0

    for right, val in enumerate(nums):
        prod *= val
        while prod >= k:
            prod //= nums[left]
            left += 1
        count += (right - left + 1) 
    return count

print(numSubarrayProductLessThanK([10, 5, 2, 6], 100))      
