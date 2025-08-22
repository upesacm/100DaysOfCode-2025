def subarray_with_given_sum(arr, target):
    start = 0
    current_sum = 0
    for end in range(len(arr)):
        current_sum += arr[end]
        while current_sum > target and start < end:
            current_sum -= arr[start]
            start += 1
        if current_sum == target:
            print(f"Subarray found from index {start} to {end}")
            return
    print("No subarray found")

subarray_with_given_sum([1, 4, 20, 3, 10, 5], 33)     # Output: 2 to 4
subarray_with_given_sum([1, 4, 0, 0, 3, 10, 5], 7)    # Output: 1 to 4
