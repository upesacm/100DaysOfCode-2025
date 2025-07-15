Your task: Set a specific bit position to 1 using bitwise operations while preserving all other 
bits.

def set_bit(n, i):
    if type(n) != int or type(i) != int:
        print("Please enter only integers.")
        return
    if i < 0:
        print("Bit position can't be negative.")
        return
    result = n | (1 << i)
    return result
