# Implement systematic pair finding using hash-based lookup or sorted traversal to identify all pairs meeting difference criteria comprehensively.

arr = list(map(int, input("Enter array elements separated by spaces: ").split()))
k = int(input("Enter difference k: "))

s = set(arr)
pairs = []

for num in arr:
    if (num + k) in s:
        pairs.append((num, num + k))

print("Output:", pairs)
