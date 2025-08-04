def find_subarray_with_sum(arr, target_sum):
    start = 0
    current_sum = 0

    for end in range(len(arr)):
        current_sum += arr[end]

        while current_sum > target_sum and start < end:
            current_sum -= arr[start]
            start += 1

        if current_sum == target_sum:
            return arr[start:end + 1]

    return []
