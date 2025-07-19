n = int(input("Enter a number: "))
add = 1
while add != 0:
    carry = n & add
    n = n ^ add
    add = carry << 1
print(n)
