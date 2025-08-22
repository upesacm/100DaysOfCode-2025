def has_pair_with_sum(arr, x):
    # First, sort the array since the two-pointer technique requires a sorted array
    arr.sort()

    left, right = 0, len(arr) - 1

    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == x:
            return True
        elif current_sum < x:
            left += 1
        else:
            right -= 1

    return False

# Example usage:
arr1 = [1, 4, 45, 6, 10, 8]
x1 = 16
print(has_pair_with_sum(arr1, x1))  # Output: True

arr2 = [1, 2, 4, 3, 6]
x2 = 10
print(has_pair_with_sum(arr2, x2))  # Output: False
