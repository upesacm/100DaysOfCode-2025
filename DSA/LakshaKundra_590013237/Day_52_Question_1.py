def has_pair_with_sum(arr, x):
    arr.sort()
    left = 0
    right = len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == x:
            return True
        elif current_sum < x:
            left += 1
        else:
            right -= 1
    return False

print(has_pair_with_sum([1, 4, 45, 6, 10, 8], 16))  # true
print(has_pair_with_sum([1, 2, 4, 3, 6], 10))       # false
