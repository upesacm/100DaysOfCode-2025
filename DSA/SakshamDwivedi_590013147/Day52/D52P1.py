#The way to complete this task in O(n) way is to sort the array before searching for the sum, if the array is unsorted then we will
#have to check all the possibilities resulting in O(n^2)
def pair_sum(arr, target):
    left = 0
    right = len(arr) - 1
    sorted_arr = sorted(arr)
    while left < right:
        sum_at = sorted_arr[left] + sorted_arr[right]
        if sum_at == target:
            return True
        elif sum_at < target:
            left += 1
        else:
            right -= 1
    return False

#Fixed Input
print(pair_sum([1, 4, 45, 6, 10, 8], 16))
print(pair_sum([1, 2, 4, 3, 6], 11))
