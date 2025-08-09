#Implement single-pass streak counting to identify maximum consecutive patterns while maintaining optimal time and space complexity.
arr = list(map(int, input("Enter binary array elements separated by space: ").split()))

max_count = 0
current_count = 0

for num in arr:
    if num == 1:
        current_count += 1
        max_count = max(max_count, current_count)
    else:
        current_count = 0

print("Output:")
print(max_count)
