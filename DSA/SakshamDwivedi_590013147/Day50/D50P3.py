def find_subarray_with_sum(arr, target):
    n = len(arr)
    start = 0
    curr_sum = 0

    for end in range(n):
        curr_sum += arr[end]

        while curr_sum > target and start <= end:
            curr_sum -= arr[start]
            start += 1

        if curr_sum == target:
            return f"Subarray found from index {start} to {end}"

    return "No subarray found"

#Fixed Input
arr = [1, 4, 20, 3, 10, 5]
target = 33
print(find_subarray_with_sum(arr, target))
