def isolated_rightMost_bit(n):
    return n & -n

num = int(input("Enter the number: "))

result = isolated_rightMost_bit(num)

print(result)