def num_subarray_product_less_than_k(nums, k):
    if k <= 1:
        return 0
    prod = 1
    count = left = 0
    for right, val in enumerate(nums):
        prod *= val
        while prod >= k:
            prod //= nums[left]
            left += 1
        count += right - left + 1
    return count

# Example Usage
print(num_subarray_product_less_than_k([10, 5, 2, 6], 100))  
print(num_subarray_product_less_than_k([1,2,3], 0))          