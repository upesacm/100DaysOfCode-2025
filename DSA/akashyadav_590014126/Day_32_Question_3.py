def find_xor(arr):
    result=0
    for i in arr:
        result ^= i
    return result

print(find_xor([1,2,3]))