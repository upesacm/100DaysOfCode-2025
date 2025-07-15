def count_set_bits(n):
    """
    Counts the number of bits set to 1 in binary representation of n
    using Brian Kernighan's algorithm.
    n: Integer
    """
    count = 0
    while n:
        n &= (n - 1)
        count += 1
    return count

if __name__ == "__main__":
    print("Input: n = 7 -> Output:", count_set_bits(7)) 
    print("Input: n = 9 -> Output:", count_set_bits(9)) 
