def find_pairs_with_difference(arr, k):
    seen = set(arr)
    result = []

    for num in arr:
        if num + k in seen:
            result.append((num, num + k))
        if num - k in seen:
            result.append((num, num - k))

    return result
