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

    print("No subarray with the given sum found.")

# Example usage
arr2 = [21,23,0,0,24]
target2 = 24
subarray_with_given_sum(arr2, target2)
