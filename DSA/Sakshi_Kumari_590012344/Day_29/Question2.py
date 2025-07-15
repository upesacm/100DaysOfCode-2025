Your task: Extract and check the value of a specific bit position using efficient bitwise 
masking operations.

def is_bit_set(n, i):
    if not isinstance(n, int) or not isinstance(i, int) or i < 0:
        print("Error: Enter valid integer inputs.")
        return
    if n & (1 << i):
        print(f"Bit at position {i} is set.")
    else:
        print(f"Bit at position {i} is not set.")

