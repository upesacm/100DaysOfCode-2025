# 1. Max Consecutive Ones
def max_consecutive_ones(nums):
    max_count = count = 0
    for num in nums:
        if num == 1:
            count += 1
            max_count = max(max_count, count)
        else:
            count = 0
    return max_count


# 2. Fruit Into Baskets (Sliding Window with Two Types)
def total_fruit(fruits):
    from collections import defaultdict

    left = 0
    fruit_count = defaultdict(int)
    max_length = 0

    for right in range(len(fruits)):
        fruit_count[fruits[right]] += 1

        while len(fruit_count) > 2:
            fruit_count[fruits[left]] -= 1
            if fruit_count[fruits[left]] == 0:
                del fruit_count[fruits[left]]
            left += 1

        max_length = max(max_length, right - left + 1)

    return max_length


# 3. Longest Mountain in Array
def longest_mountain(arr):
    n = len(arr)
    max_len = 0
    i = 1

    while i < n - 1:
        # Check if i is a peak
        if arr[i - 1] < arr[i] > arr[i + 1]:
            left = i - 1
            right = i + 1

            # Expand left
            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1

            # Expand right
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1

            max_len = max(max_len, right - left + 1)
            i = right  # Move to next position after mountain
        else:
            i += 1

    return max_len


# ----------------------------
# Example Calls

# 1. Max Consecutive Ones
print("Max Consecutive Ones:", max_consecutive_ones([1, 1, 0, 1, 1, 1]))  # Output: 3
print("Max Consecutive Ones:", max_consecutive_ones([1, 0, 1, 1, 0, 1]))  # Output: 2

# 2. Fruit Into Baskets
print("Max Fruits Collected:", total_fruit([1, 2, 1]))                    # Output: 3
print("Max Fruits Collected:", total_fruit([0, 1, 2, 2]))                # Output: 3

# 3. Longest Mountain
print("Longest Mountain Length:", longest_mountain([2, 1, 4, 7, 3, 2, 5]))  # Output: 5
print("Longest Mountain Length:", longest_mountain([2, 2, 2]))             # Output: 0
