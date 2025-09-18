def max_subarray_sum(nums):
    """
    Finds maximum sum of any contiguous subarray using Kadane's algorithm.
    Time: O(n), Space: O(1)
    """
    if not nums:
        return 0
    current_sum = max_sum = nums[0]
    for i in range(1, len(nums)):
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)
    return max_sum

if __name__ == "__main__":
    print(max_subarray_sum([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  # Output: 6
    print(max_subarray_sum([1]))  # Output: 1