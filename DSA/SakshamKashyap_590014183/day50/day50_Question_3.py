def subarray_with_given_sum(arr, target):
    n = len(arr)
    curr_sum = 0
    start = 0

    for end in range(n):
        curr_sum += arr[end]
        while curr_sum > target and start <= end:
            curr_sum -= arr[start]
            start += 1
        if curr_sum == target:
            # Returning indices `start` to `end`
            return f"Subarray found from index {start} to {end}"
    return "No subarray with given sum exists"

# Example usage:
arr1 = [1, 4, 20, 3, 10, 5]
target1 = 33
print(subarray_with_given_sum(arr1, target1))  # Output: Subarray found from index 2 to 4

arr2 = [1, 4, 0, 0, 3, 10, 5]
target2 = 7
print(subarray_with_given_sum(arr2, target2))  # Output: Subarray found from index 1 to 4
