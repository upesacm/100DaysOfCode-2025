def has_pair_with_sum(arr, target):
    left = 0
    right = len(arr) - 1

    while left < right:
        current_sum = arr[left] + arr[right]

        if current_sum == target:
            print(f"Pair found: ({arr[left]}, {arr[right]})")
            return True
        elif current_sum < target:
            left += 1
        else:
            right -= 1

    print(f"No pair found with sum {target}")
    return False
