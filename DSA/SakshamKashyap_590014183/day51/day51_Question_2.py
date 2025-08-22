def smallest_subarray_with_sum_greater_than_x(arr, x):
    n = len(arr)
    min_length = n + 1
    curr_sum = 0
    start = 0
    
    for end in range(n):
        curr_sum += arr[end]
        
        while curr_sum > x:
            min_length = min(min_length, end - start + 1)
            curr_sum -= arr[start]
            start += 1
    
    if min_length == n + 1:
        return 0  # No valid subarray found
    else:
        return min_length

# Example usage:
arr1 = [1, 4, 45, 6, 0, 19]
x1 = 51
print(smallest_subarray_with_sum_greater_than_x(arr1, x1))  # Output: 3

arr2 = [1, 10, 5, 2, 7]
x2 = 9
print(smallest_subarray_with_sum_greater_than_x(arr2, x2))  # Output: 1
