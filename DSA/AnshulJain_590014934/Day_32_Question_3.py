# Find XOR of all numbers in an array
def find_xor(arr):
    result = 0
    for num in arr:
        result ^= num
    return result
# Taking input from the user
input_str = input("Enter integers separated by spaces: ")
arr = list(map(int, input_str.split()))
xor_result = find_xor(arr)
print(f"The XOR of all elements is: {xor_result}")
#for example:
# Input: 1 2 3 4    
# Output: 4 