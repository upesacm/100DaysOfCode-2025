def subarray_product_less(nums, k):
    if k <= 1:
        return 0

    prod = 1
    left = 0
    count = 0

    for right in range(len(nums)):
        prod *= nums[right]
        while prod >= k:
            prod //= nums[left]
            left += 1
        count += right - left + 1

    return count

#Fixed Input
nums = [10, 5, 2, 6]
k = 100
print(subarray_product_less(nums, k))
