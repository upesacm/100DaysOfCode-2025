def turn_off_rightmost_set_bit(n):
    """
    Turn off the rightmost set bit.
    Using: n & (n - 1)
    """
    return n & (n - 1)

print("\n2. Turn Off the Rightmost Set Bit")
print("Input: n = 12 -> Output:", turn_off_rightmost_set_bit(12))  
print("Input: n = 10 -> Output:", turn_off_rightmost_set_bit(10)) 