# Extract and check the value of a specific bit position using efficient bitwise masking operations.

n = int(input("Enter the number (n): "))
i = int(input("Enter the bit position to check (i): "))

if (n & (1 << i)) != 0:
    print(1)
else:
    print(0)
