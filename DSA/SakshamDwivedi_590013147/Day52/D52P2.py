#This works in O(n logn) time when the given array is not sorted but O(n) time if the array is already
def pair_diff(arr, target):
    i = 0
    j = 1
    l = len(arr)
    sorted_arr = sorted(arr)
    result = []
    while i < l and j < l:
        if i == j:
            j += 1
            continue
        if sorted_arr[j] - sorted_arr[i] == target:
            result.append((sorted_arr[j], sorted_arr[i]))
            j += 1
        elif sorted_arr[j] - sorted_arr[i] > target:
            i += 1
        else:
            j += 1
    return result

#Fixed Input
print(pair_diff([1, 5, 3, 4, 2], 2))
