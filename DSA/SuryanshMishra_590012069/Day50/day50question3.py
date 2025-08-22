# 3. Subarray with Given Sum
# A problem that teaches variable-size sliding window techniques and demonstrates dynamic window adjustment algorithms for target sum finding using efficient pointer-based traversal methods.

# Given an array of non-negative integers and a target sum, find the subarray with the given sum using sliding window technique. This operation is fundamental in subarray analysis and target finding where you need to locate specific sum ranges within arrays efficiently. The technique uses variable-size sliding window with two pointers that expand and contract dynamically to match the target sum. This concept is essential in financial analysis, resource allocation, and optimization problems where finding segments that meet specific criteria enables decision making and resource planning in array-based data structures.

# This teaches variable sliding window algorithms and dynamic window adjustment techniques that are essential for target finding and efficient subarray sum computation operations.

# Your task: Implement dynamic sliding window with two pointers to find subarrays matching target sums through efficient window expansion and contraction.

# Examples
# Input:

# arr = [1, 4, 20, 3, 10, 5], target = 33
# Output:

# Subarray found from index 2 to 4
# Input:

# arr = [1, 4, 0, 0, 3, 10, 5], target = 7
# Output:

# Subarray found from index 1 to 4
def find_subarray_with_sum(arr, target):
    start = 0
    current_sum = 0

    for end in range(len(arr)):
        current_sum += arr[end]

        while current_sum > target and start <= end:
            current_sum -= arr[start]
            start += 1

        if current_sum == target:
            return f"Subarray found from index {start} to {end}"

    return "No subarray with given sum found"
