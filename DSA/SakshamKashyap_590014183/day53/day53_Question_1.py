def max_consecutive_ones(arr):
    max_count = 0
    current_count = 0

    for num in arr:
        if num == 1:
            current_count += 1
            max_count = max(max_count, current_count)
        else:
            current_count = 0
    return max_count

# Example usage:
print(max_consecutive_ones([1,1,0,1,1,1]))  # Output: 3
print(max_consecutive_ones([1,0,1,1,0,1]))  # Output: 2
