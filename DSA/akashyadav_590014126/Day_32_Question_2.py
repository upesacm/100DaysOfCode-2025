def find_unique(arr):
    result=0
    for i in arr:
        result ^= i
    return result

print(find_unique([1,2,3,2,1]))