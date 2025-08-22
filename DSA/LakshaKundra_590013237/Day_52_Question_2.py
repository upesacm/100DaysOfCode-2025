def find_pairs_with_difference(arr, k):
    result = []
    s = set(arr)
    for num in arr:
        if num + k in s:
            result.append((num, num + k))
        if num - k in s:
            result.append((num, num - k))
    return result

print(find_pairs_with_difference([1, 5, 3, 4, 2], 2))    # [(1, 3), (3, 5), (5, 3), (4, 2)]
print(find_pairs_with_difference([8, 12, 16, 4, 0, 20], 4))  # [(8, 12), (12, 16), (16, 20)]
