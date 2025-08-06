def smallest_subarray_greater_than_x(arr, x):
    n = len(arr)
    min_len = float('inf')
    left = 0
    curr_sum = 0
    for right in range(n):
        curr_sum += arr[right]
        while curr_sum > x:
            min_len = min(min_len, right - left + 1)
            curr_sum -= arr[left]
            left += 1
    return min_len if min_len != float('inf') else 0

arr = [1, 4, 45, 6, 0, 19]
x = 51
result = smallest_subarray_greater_than_x(arr, x)
print(result)  