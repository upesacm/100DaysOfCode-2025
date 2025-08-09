# Implement prefix sum tracking with hash map storage to efficiently find longest subarrays meeting exact sum requirements.
arr = list(map(int, input("Enter array elements separated by space: ").split()))
k = int(input("Enter value of k: "))

prefix_sum = 0
sum_map = {}
max_len = 0

for i in range(len(arr)):
    prefix_sum += arr[i]
    if prefix_sum == k:
        max_len = i + 1
    if (prefix_sum - k) in sum_map:
        max_len = max(max_len, i - sum_map[prefix_sum - k])
    if prefix_sum not in sum_map:
        sum_map[prefix_sum] = i

print("Length of longest subarray:", max_len)
