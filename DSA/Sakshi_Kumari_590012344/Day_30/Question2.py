Your task: Toggle a specific bit position using XOR operations to flip its current state 
efficiently.

def toggle_bit(number, bit_position):
    if type(number) is not int or type(bit_position) is not int:
        raise TypeError("Inputs must be integers.")
    if bit_position < 0:
        raise ValueError("Bit position cannot be negative.")
    return number ^ (1 << bit_position)
