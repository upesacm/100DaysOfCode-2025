#Check if a number's binary representation is palindromic using efficient bit manipulation without string conversion.
n = int(input("Enter a number: "))

def is_binary_palindrome(n):
    bits = []
    temp = n
    while temp > 0:
        bits.append(temp & 1)
        temp >>= 1
    return bits == bits[::-1]

print("Output:", "Yes" if is_binary_palindrome(n) else "No")
