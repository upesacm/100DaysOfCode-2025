def ith_bit(num, i):
    bit = (num >> i) & 1
    return bit

#Fixed Input
print(ith_bit(4, 2))

#Custom Input
num = int(input("Enter the number : "))
i = int(input("Enter i : "))
print(ith_bit(num, i))
