def toggle_ith_bit(n, i):
    """
    Toggles the i-th bit of number n (0 -> 1 or 1 -> 0).
    n: Integer
    i: Bit index (0-based from right)
    """
    return n ^ (1 << i)

if __name__ == "__main__":
    print("Input: n = 10, i = 1 -> Output:", toggle_ith_bit(10, 1)) 
    print("Input: n = 5, i = 2 -> Output:", toggle_ith_bit(5, 2))   