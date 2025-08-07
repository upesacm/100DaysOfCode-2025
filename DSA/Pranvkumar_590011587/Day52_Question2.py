def find_pairs_with_difference(arr, k):
    seen = set(arr)
    pairs = set()
    for num in arr:
        if num + k in seen:
            pairs.add((num, num + k))
        if num - k in seen:
            pairs.add((num, num - k))
    return list(pairs)

# Example usage:
print(find_pairs_with_difference([1, 5, 3, 4, 2], 2))  
print(find_pairs_with_difference([8, 12, 16, 4, 0, 20], 4))  