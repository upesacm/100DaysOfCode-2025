# Find the only non-repeating element using XOR
# Taking input from the user
input_str = input("Enter integers separated by spaces (all elements appear twice except one): ")
arr = list(map(int, input_str.split()))
result = 0
for num in arr:
    result ^= num
print(f"The non-repeating element is: {result}")
#for example:
# Input: 1 2 3 2 1  
# Output: 3