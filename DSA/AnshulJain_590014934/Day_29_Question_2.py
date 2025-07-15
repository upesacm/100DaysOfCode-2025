n = int(input("Enter a number: ")) # Taking input from the user
i = int(input("Enter the bit position to check (0-indexed): "))  # Taking input for bit position
if n & (1 << i):
    print(1)
else:
    print(0)
#for example:
# Input: 5, Bit Position: 0
# Output: 1
