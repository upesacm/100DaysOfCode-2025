# 1. Maximum Sum Subarray of Size K
# A problem that introduces sliding window optimization techniques and teaches fixed-size subarray analysis using efficient window-based computation methods for array processing and optimization.

# Given an array and a number k, find the maximum sum of a subarray of size k using a sliding window approach. This operation is fundamental in array optimization and window-based analysis where you need to find optimal segments within larger datasets efficiently. The technique uses sliding window optimization to avoid redundant calculations by maintaining a moving window and updating sums incrementally. This concept is essential in signal processing, time series analysis, and performance monitoring where finding peak values within fixed intervals enables trend analysis and anomaly detection in continuous data streams.

# This teaches sliding window algorithms and fixed-size optimization techniques that are essential for array analysis and efficient subarray computation operations.

# Your task: Implement sliding window technique to find the maximum sum subarray by maintaining a moving window and updating sums efficiently.

# Examples
# Input:

# arr = [1, 4, 2, 10], k = 2
# Output:

# 12
# Input:

# arr = [100, 200, 300, 400], k = 2
# Output:

# 700
def max_sum_subarray(arr, k):
    n = len(arr)
    if n < k:
        return None
    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)

    return max_sum
