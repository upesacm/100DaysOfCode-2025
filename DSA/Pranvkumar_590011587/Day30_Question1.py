def clear_ith_bit(n, i):
    """
    Clears the i-th bit of number n (sets it to 0).
    n: Integer
    i: Bit index (0-based from right)
    """
    return n & ~(1 << i)

if __name__ == "__main__":
    print("Input: n = 7, i = 1 -> Output:", clear_ith_bit(7, 1))  
    print("Input: n = 10, i = 3 -> Output:", clear_ith_bit(10, 3)) 