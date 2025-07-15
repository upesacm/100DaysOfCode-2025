n, i = map(int, input("Enter the number and bit position: ").split())
mask = 1 << i
result = n | mask
print(result)