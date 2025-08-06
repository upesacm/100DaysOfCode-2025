# 1. Check Array for Pair with Sum using Two-Pointer Technique
def has_pair_with_sum(arr, x):
    arr.sort()  # Ensure it's sorted
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


# 2. Find All Pairs with Given Difference
def find_pairs_with_difference(arr, k):
    seen = set(arr)
    pairs = []

    for num in arr:
        if (num + k) in seen:
            pairs.append((num, num + k))
        if (num - k) in seen:
            pairs.append((num, num - k))

    # Optional: remove duplicates
    unique_pairs = list(set(pairs))
    return unique_pairs


# 3. Trapping Rain Water using Two-Pointer Technique
def trap_rain_water(height):
    if not height or len(height) < 3:
        return 0

    left, right = 0, len(height) - 1
    left_max = right_max = 0
    total_water = 0

    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                total_water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                total_water += right_max - height[right]
            right -= 1

    return total_water


# Example Calls:

# 1. Check Array for Pair with Sum
print("Pair with Sum Exists:", has_pair_with_sum([1, 4, 45, 6, 10, 8], 16))  # True

# 2. Find All Pairs with Given Difference
print("Pairs with Difference 2:", find_pairs_with_difference([1, 5, 3, 4, 2], 2))
# Output may vary depending on duplicates

# 3. Trapping Rain Water
print("Trapped Rain Water:", trap_rain_water([0,1,0,2,1,0,1,3,2,1,2,1]))  # Output: 6
