#  Clear a specific bit position to 0 using bitwise operations while preserving all other bits.
n = int(input("Enter the number (n): "))
i = int(input("Enter the bit position to clear (i): "))

new_n = n & ~(1 << i)

print(new_n)
