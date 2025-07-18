# Find XOR of All Numbers in an Array 
arr = list(map(int, input("Enter numbers separated by space: ").split()))
xor_result = 0
for num in arr:
    xor_result ^= num

print("XOR of all elements:", xor_result)
