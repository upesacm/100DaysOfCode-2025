Your task: Count the number of set bits in an integer using efficient bit manipulation 
techniques beyond simple iteration.
  
def count_set_bits(n):
    if not isinstance(n, int):
        raise TypeError("Input must be an integer.")
    if n < 0:
        raise ValueError("Input must be a non-negative integer.")

    count = 0
    while n:
        n &= (n - 1)
        count += 1
    return count
