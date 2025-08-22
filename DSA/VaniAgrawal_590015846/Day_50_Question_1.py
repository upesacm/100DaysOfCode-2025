#: Implement sliding window technique to find the maximum sum subarray by maintaining a moving window and updating sums efficiently.
arr = list(map(int, input("Enter the array elements separated by space: ").split()))
k = int(input("Enter the value of k: "))

if k > len(arr):
    print("k cannot be larger than the array size.")
else:
    window_sum = sum(arr[:k])
    max_sum = window_sum
  
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)

    print("Maximum sum of subarray of size k:", max_sum)
