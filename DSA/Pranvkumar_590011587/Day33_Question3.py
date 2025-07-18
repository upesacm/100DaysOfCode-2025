def isolate_rightmost_set_bit(n):
    """
    Isolate the rightmost set bit.
    Using: n & -n
    """
    return n & -n

print("\n3. Isolate the Rightmost Set Bit")
print("Input: n = 10 -> Output:", isolate_rightmost_set_bit(10)) 
print("Input: n = 12 -> Output:", isolate_rightmost_set_bit(12))  
