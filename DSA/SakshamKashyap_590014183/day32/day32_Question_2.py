def find_unique(arr):
    result = 0
    for num in arr:
        result ^= num
    return result


print(find_unique([2, 3, 2]))       
print(find_unique([5, 1, 1, 5, 7])) 
