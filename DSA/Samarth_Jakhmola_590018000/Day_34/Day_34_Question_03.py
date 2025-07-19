def check_binary_palindrome(n):
    if n < 0:
        return "No"
        
    msb = 0     # msb = most significant bit
    temp = n
    while temp > 0:
        msb += 1
        temp >>= 1
    msb -= 1

    lsb = 0

    while lsb < msb:
        left_bit = (n >> msb) & 1
        right_bit = (n >> lsb) & 1
        if left_bit != right_bit:
            return "No"
        lsb += 1
        msb -= 1

    return "Yes"
    
try:
    n = int(input("Enter an integer : "))
    print(check_binary_palindrome(n))
except:
    print("Invalid input. Please try with a valid input.")
