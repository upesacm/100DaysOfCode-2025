n, i = map(int, input("Enter number and bit position: ").split())
bit = (n >> i) & 1
print(bit)