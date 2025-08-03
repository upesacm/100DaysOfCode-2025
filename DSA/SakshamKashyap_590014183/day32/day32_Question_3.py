def xor_all(arr):
    result = 0
    for num in arr:
        result ^= num
    return result

print(xor_all([1, 2, 3]))  
print(xor_all([4, 5, 6]))  
