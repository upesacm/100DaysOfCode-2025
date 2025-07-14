n = int(input("Enter a number: ")) # Taking input from the user
i = int(input("Enter the bit position to set (0-indexed): ")) 
print(n | (1 << i))
#for example:
# Input: 5, Bit Position: 1
# Output: 7
