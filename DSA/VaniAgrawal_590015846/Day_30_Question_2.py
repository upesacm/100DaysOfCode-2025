#: Toggle a specific bit position using XOR operations to flip its current state efficiently.
n = int(input("Enter the number (n): "))
i = int(input("Enter the bit position to toggle (i): "))

new_n = n ^ (1 << i)

print(new_n)
