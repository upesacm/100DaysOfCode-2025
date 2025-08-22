def subarray_with_sum(arr, target):
    left = 0
    curr_sum = 0
    for right in range(len(arr)):
        curr_sum += arr[right]
        while curr_sum > target and left <= right:
            curr_sum -= arr[left]
            left += 1
        if curr_sum == target:
            return f"Subarray found from index {left} to {right}"

    return "No subarray with given sum found"

# Example usage:
print(subarray_with_sum([1, 4, 20, 3, 10, 5], 33))    
print(subarray_with_sum([1, 4, 0, 0, 3, 10, 5], 7))     