def total_fruit(fruits):
    from collections import defaultdict

    count = defaultdict(int)
    left = 0
    max_length = 0

    for right, fruit in enumerate(fruits):
        count[fruit] += 1

        # If there are more than 2 types in the current window, shrink it
        while len(count) > 2:
            count[fruits[left]] -= 1
            if count[fruits[left]] == 0:
                del count[fruits[left]]
            left += 1

        # Update maximum window length
        max_length = max(max_length, right - left + 1)

    return max_length

# Example usage:
print(total_fruit([1, 2, 1]))      # Output: 3
print(total_fruit([0, 1, 2, 2]))   # Output: 3
