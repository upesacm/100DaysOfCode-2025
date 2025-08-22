# 1. Max Consecutive Ones
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


# 2. Fruit Into Baskets (Longest subarray with at most 2 distinct elements)
def fruit_into_baskets(fruits):
    from collections import defaultdict

    left = 0
    fruit_count = defaultdict(int)
    max_length = 0

    for right in range(len(fruits)):
        fruit_count[fruits[right]] += 1

        # Shrink window if more than 2 types
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
        if arr[i - 1] < arr[i] > arr[i + 1]:  # peak detected
            left = i - 1
            right = i + 1

            while left > 0 and arr[left - 1] < arr[left]:
                left -= 1
            while right < n - 1 and arr[right] > arr[right + 1]:
                right += 1

            max_len = max(max_len, right - left + 1)
            i = right
        else:
            i += 1

    return max_len


# ------------------------------
# Example Inputs and Outputs
if __name__ == "__main__":
    # Problem 1: Max Consecutive Ones
    print("Max Consecutive Ones:")
    print("Input: [1,1,0,1,1,1] → Output:", max_consecutive_ones([1, 1, 0, 1, 1, 1]))  # 3
    print("Input: [1,0,1,1,0,1] → Output:", max_consecutive_ones([1, 0, 1, 1, 0, 1]))  # 2

    # Problem 2: Fruit Into Baskets
    print("\nFruit Into Baskets:")
    print("Input: [1,2,1] → Output:", fruit_into_baskets([1, 2, 1]))  # 3
    print("Input: [0,1,2,2] → Output:", fruit_into_baskets([0, 1, 2, 2]))  # 3

    # Problem 3: Longest Mountain
    print("\nLongest Mountain in Array:")
    print("Input: [2,1,4,7,3,2,5] → Output:", longest_mountain([2, 1, 4, 7, 3, 2, 5]))  # 5
    print("Input: [2,2,2] → Output:", longest_mountain([2, 2, 2]))  # 0
