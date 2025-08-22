arr = list(map(int, input("Enter binary array elements separated by space: ").split()))
max_count = count = 0
for num in arr:
    if num == 1:
        count += 1
        if count > max_count:
            max_count = count
    else:
        count = 0
print("Maximum consecutive 1s:", max_count)
#for example:
# Input: 1 1 0 1 1 1 0 1
# Output: Maximum consecutive 1s: 3