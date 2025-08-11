def maxSumSubarray(arr, n, k):
    """
    Finds the maximum sum of a subarray of a given size k using the sliding window technique.

    Args:
        arr: The input array.
        n: The size of the array.
        k: The size of the subarray window.

    Returns:
        The maximum sum of a subarray of size k, or -1 if n < k.
    """
    # Handle edge case where the array is smaller than the window size
    if n < k:
        return -1

    # Calculate sum of the first window
    windowSum = sum(arr[:k])

    # Initialize maxSum with the first window's sum
    maxSum = windowSum

    # Slide the window from the k-th element to the end
    for i in range(k, n):
        # Update windowSum by adding the new element and subtracting the old one
        windowSum += arr[i] - arr[i - k]
        # Update maxSum if the current window's sum is greater
        maxSum = max(maxSum, windowSum)

    return maxSum

# Main part of the program
if __name__ == "__main__":
    arr = [2, 1, 5, 1, 3, 2]
    n = len(arr)
    k = 3
    result = maxSumSubarray(arr, n, k)
    print(f"Max sum of subarray of size {k}: {result}")
