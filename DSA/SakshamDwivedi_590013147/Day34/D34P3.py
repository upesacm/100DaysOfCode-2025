#Solution Function
def is_palindrome(num):
    num_bits = 0
    temp = num
    while temp > 0:
        num_bits += 1
        temp >>= 1
    for i in range(num_bits//2):
        left = (num >> (num_bits - 1 - i)) & 1
        right = (num >> i) & 1
        if left != right:
            return False
    return True

#Fixed Input
print(is_palindrome(9))

#Custom Input
num = int(input("Enter the number : "))
print(is_palindrome(num))
