def num_subarray_product_less_than_k(nums, k):
    if k <= 1:
        return 0
    prod = 1
    left = 0
    count = 0
    for right in range(len(nums)):
        prod *= nums[right]
        while prod >= k:
            prod /= nums[left]
            left += 1
        count += right - left + 1
    return count

n, k = map(int, input().split())
nums = list(map(int, input().split()))
print(num_subarray_product_less_than_k(nums, k))
