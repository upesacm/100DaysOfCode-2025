n = int(input("Enter any number: "))
original = n
reverse = 0
while n > 0:
    reverse = (reverse << 1) | (n & 1)
    n >>= 1
print("Yes" if original == reverse else "No")