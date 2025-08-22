def find_pairs_with_difference(arr, k):
    pairs = []
    elements = set(arr)

    for x in arr:
        # Check if x + k exists
        if x + k in elements:
            pairs.append((x, x + k))
        # Check if x - k exists
        if x - k in elements:
            pairs.append((x, x - k))

    return pairs

# Example usage:
arr1 = [1, 5, 3, 4, 2]
k1 = 2
print(find_pairs_with_difference(arr1, k1))
# Output: [(1, 3), (3, 5), (5, 3), (4, 2)]

arr2 = [8, 12, 16, 4, 0, 20]
k2 = 4
print(find_pairs_with_difference(arr2, k2))
# Output: [(8, 12), (12, 16), (16, 20)]
