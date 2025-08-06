def has_pair_with_sum(arr, x):
    left, right = 0, len(arr) - 1
    while left < right:
        total = arr[left] + arr[right]
        if total == x:
            return True
        elif total < x:
            left += 1
        else:
            right -= 1
    return False

# Example usage:
print(has_pair_with_sum([1, 4, 6, 8, 10, 45], 16))  
print(has_pair_with_sum([1, 2, 3, 4, 6], 10))      