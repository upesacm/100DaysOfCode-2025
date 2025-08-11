# Implement sliding window with type constraint tracking to find maximum subarray length containing exactly two distinct elements efficiently.
arr = list(map(int, input("Enter array elements separated by space: ").split()))

from collections import defaultdict

basket = defaultdict(int)
left = 0
max_length = 0

for right in range(len(arr)):
    basket[arr[right]] += 1

    while len(basket) > 2:
        basket[arr[left]] -= 1
        if basket[arr[left]] == 0:
            del basket[arr[left]]
        left += 1

    max_length = max(max_length, right - left + 1)

print("Output:")
print(max_length)
